#include "filter.hpp"
#include "book.hpp"
#include "ftxui/component/component.hpp"
#include <ftxui/component/component_base.hpp>

ftxui::Component
ModalComponent(std::shared_ptr<std::vector<Book>> books,
               std::string &title_input, std::string &author_input,
               std::string &year_input, std::string &isbn_input,
               std::string &price_input, std::function<void()> hide_modal) {

  auto input_title = ftxui::Input(&title_input, "Title");
  auto input_author = ftxui::Input(&author_input, "Author");
  auto input_year = ftxui::Input(&year_input, "Year");
  auto input_isbn = ftxui::Input(&isbn_input, "ISBN");
  auto input_price = ftxui::Input(&price_input, "Price");

  auto add_button = Button(
      "Save",
      [=, &title_input, &author_input, &year_input, &isbn_input,
       &price_input]() {
        uint32_t year = 0;
        uint32_t price = 0;
        if (!year_input.empty()) {
          year = static_cast<uint32_t>(std::stoi(year_input));
        }
        if (!year_input.empty()) {
          price = static_cast<uint32_t>(std::stoi(price_input));
        }
        books->push_back(
            Book{title_input, author_input, year, isbn_input, price});
        hide_modal();
      },
      ftxui::ButtonOption::Ascii()

  );

  auto cancel_button =
      ftxui::Button("Cancel", hide_modal, ftxui::ButtonOption::Ascii());

  auto btns_cntr =
      ftxui::Container::Horizontal({add_button, cancel_button}) | ftxui::center;

  auto form = ftxui::Container::Vertical({input_title, input_author, input_year,
                                          input_isbn, input_price, btns_cntr});

  return Renderer(form, [form] {
    return ftxui::vbox({
               ftxui::text("Add New Book") | ftxui::center,
               ftxui::separator(),
               form->Render(),
           }) |
           ftxui::border | size(ftxui::WIDTH, ftxui::GREATER_THAN, 40) |
           size(ftxui::HEIGHT, ftxui::GREATER_THAN, 8) | ftxui::center;
  });
}

ModalState createAddModal(std::shared_ptr<std::vector<Book>> books) {
  auto title_input = std::make_shared<std::string>("");
  auto author_input = std::make_shared<std::string>("");
  auto year_input = std::make_shared<std::string>("");
  auto isbn_input = std::make_shared<std::string>("");
  auto price_input = std::make_shared<std::string>("");
  auto show_flag = std::make_shared<bool>(false);

  auto hide = [show_flag, title_input, author_input, year_input, isbn_input,
               price_input]() { *show_flag = false; };

  auto modal_comp =
      ModalComponent(books, *title_input, *author_input, *year_input,
                     *isbn_input, *price_input, hide);

  auto modal_decorator = ftxui::Modal(modal_comp, show_flag.get());

  return {show_flag, modal_decorator};
}
