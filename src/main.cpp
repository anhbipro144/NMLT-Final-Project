#include "ascii.hpp"
#include "book.hpp"
#include "filter.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <string>
#include <vector>

using namespace ftxui;

Component create_book_list_component(std::shared_ptr<std::vector<Book>> books,
                                     Filter &filter, int page_size,
                                     int &current_page) {
  return Renderer([books, &filter, page_size, &current_page] {
    Elements rows;

    // iterator
    auto begin = books->begin() + current_page * page_size;
    auto end = std::min(begin + page_size, books->end());

    for (auto it = begin; it != end; ++it) {
      bool matches = true;

      if (!filter.title.empty() &&
          to_lower(it->title_).find(to_lower(filter.title)) ==
              std::string::npos) {
        matches = false;
      }
      if (!filter.author.empty() &&
          to_lower(it->author_).find(to_lower(filter.author)) ==
              std::string::npos) {
        matches = false;
      }

      if (!filter.year.empty() &&
          to_lower(std::to_string(it->year_)).find(to_lower(filter.year)) ==
              std::string::npos) {
        matches = false;
      }

      if (!filter.isbn.empty() && to_lower(it->isbn_).find(to_lower(
                                      filter.isbn)) == std::string::npos) {
        matches = false;
      }

      if (!filter.price.empty() &&
          to_lower(std::to_string(it->price_)).find(to_lower(filter.price)) ==
              std::string::npos) {
        matches = false;
      }

      if (!matches)
        continue;

      auto title =
          AsciiArtElement(make_ascii(it->title_, Font::larry3d)) | center;
      auto author = text(it->author_) | center;
      auto year = text(std::to_string(it->year_)) | center;
      auto price = text(std::to_string(it->price_)) | center;
      auto isbn = text(it->isbn_) | center;
      auto wrapper = vbox(author, year, price, isbn);

      rows.push_back(vbox({title, separator(), wrapper}) | border |
                     size(WIDTH, EQUAL, 105));
    }

    if (rows.empty())
      return text("No books match your filter.") | center | border;

    FlexboxConfig cfg;
    cfg.direction = FlexboxConfig::Direction::Row;
    cfg.wrap = FlexboxConfig::Wrap::Wrap;
    cfg.gap_x = 1;

    return flexbox(rows, cfg);
  });
}

int main() {
  auto books_ptr = std::make_shared<std::vector<Book>>(std::vector<Book>{
      {"Great Gatsby", "F. Scott Fitzgerald", 1925, "9780141182636", 150000},
      {"Mockingbird", "Harper Lee", 1960, "9780446310789", 180000},
      {"1984", "George Orwell", 1949, "9780141036144", 200000},
      {"Pride", "Jane Austen", 1813, "9780141439518", 160000},
      {"The Catcher", "J.D. Salinger", 1951, "9780316769174", 170000},
      {"The Rings", "J.R.R. Tolkien", 1954, "9780618640157", 220000},
      {"The Hobbit", "J.R.R. Tolkien", 1937, "9780261102217", 190000},
      {"Fahrenheit", "Ray Bradbury", 1953, "9780006546061", 155000},
      {"Dracula", "Bram Stoker", 1897, "9780141439846", 165000},
  });

  const int page_size = 6;
  int current_page = 0;
  int total_pages = (books_ptr->size() + page_size - 1) / page_size;

  Filter filter;
  auto title = AsciiArt(make_ascii("Book management C++/FTXUI"));

  Component page_list_ctnr =
      create_book_list_component(books_ptr, filter, page_size, current_page);

  auto [show, modal] = createAddModal(books_ptr);

  Component prev_button = Button(
      "Prev",
      [&] {
        if (current_page > 0)
          --current_page;
      },

      ButtonOption::Ascii());

  Component next_button = Button(
      "Next",
      [&] {
        if (current_page + 1 < total_pages)
          ++current_page;
      },
      ButtonOption::Ascii()
  );

  auto paginate_btns = Container::Horizontal({prev_button, next_button});

  Component add_button =
      Button("Add", [&] { *show = true; }, ButtonOption::Ascii());

  auto screen = ScreenInteractive::Fullscreen();

  Component exit_button =
      Button("Exit", screen.ExitLoopClosure(), ButtonOption::Ascii());

  auto main_ctnr =
      Container::Vertical({filter.container, paginate_btns, add_button,
                           exit_button, page_list_ctnr, exit_button});

  auto main_renderer =
      Renderer(
          main_ctnr,
          [&] {
            auto control = flexbox(
                {paginate_btns->Render(), add_button->Render()},
                {.direction = FlexboxConfig::Direction::Row,
                 .justify_content = FlexboxConfig::JustifyContent::SpaceBetween,
                 .gap_y = 1});

            return vbox({title->Render(), filter.container->Render(), control,
                         page_list_ctnr->Render(), exit_button->Render()}) |
                   border;
          }) |
      modal;

  screen.Loop(main_renderer);

  return EXIT_SUCCESS;
}
