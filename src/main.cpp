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

 bool matches_filter(const Book& b, const Filter& filter) {
  if (!filter.title.empty() &&
      to_lower(b.title_).find(to_lower(filter.title)) == std::string::npos)
    return false;

  if (!filter.author.empty() &&
      to_lower(b.author_).find(to_lower(filter.author)) == std::string::npos)
    return false;

  if (!filter.year.empty() &&
      to_lower(std::to_string(b.year_)).find(to_lower(filter.year)) == std::string::npos)
    return false;

  if (!filter.isbn.empty() &&
      to_lower(b.isbn_).find(to_lower(filter.isbn)) == std::string::npos)
    return false;

  if (!filter.price.empty() &&
      to_lower(std::to_string(b.price_)).find(to_lower(filter.price)) == std::string::npos)
    return false;

  return true;
}

 std::vector<const Book*> filter_books(const std::vector<Book>& books, const Filter& filter) {
  std::vector<const Book*> out;
  out.reserve(books.size());
  for (const auto& b : books) {
    if (matches_filter(b, filter))
      out.push_back(&b);
  }
  return out;
}



Component create_book_list_component(std::shared_ptr<std::vector<Book>> books,
                                     Filter &filter, int page_size,
                                     int &current_page) {
  return Renderer([books, &filter, page_size, &current_page] {
    Elements rows;

    auto filtered = filter_books(*books, filter);

    // iterator
    int total_pages = (filtered.size() + page_size - 1) / page_size;

    if (current_page >= total_pages) {
      current_page = std::max(0, total_pages - 1);
    }

    int start = current_page * page_size;
    int end = std::min(start + page_size, static_cast<int>(filtered.size()));

    for (int i = start; i < end; ++i) {
      const Book& book = *filtered[i];

      auto title = AsciiArtElement(make_ascii(book.title_, Font::larry3d)) | center;
      auto author = text(book.author_) | center;
      auto year = text(std::to_string(book.year_)) | center;
      auto price = text(std::to_string(book.price_)) | center;
      auto isbn = text(book.isbn_) | center;
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
