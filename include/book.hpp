#ifndef book_hpp
#define book_hpp

#include <cstdint>
#include <ftxui/component/component.hpp>
#include <string>

struct Filter {
  std::string title = "";
  std::string author = "";
  std::string year = "";
  std::string isbn = "";
  std::string price = "";

  ftxui::Component title_input;
  ftxui::Component author_input;
  ftxui::Component year_input;
  ftxui::Component isbn_input;
  ftxui::Component price_input;
  ftxui::Component container;

  Filter()
      : title_input(ftxui::Input(&title, "Filter by title")),
        author_input(ftxui::Input(&author, "Filter by author")),
        year_input(ftxui::Input(&year, "Filter by year")),
        isbn_input(ftxui::Input(&isbn, "Filter by isbn")),
        price_input(ftxui::Input(&price, "Filter by price")),
        container(ftxui::Container::Vertical(
                      {title_input, author_input, year_input, isbn_input, price_input}) |
                  ftxui::border)

  {}
};

class Book {
public:
  std::string title_;
  std::string author_;
  std::uint32_t year_;
  std::string isbn_;
  std::uint32_t price_;

  Book(std::string title, std::string author, std::uint32_t year,
       std::string isbn, std::uint32_t price)
      : title_(title), author_(author), year_(year), isbn_(isbn),
        price_(price) {}
};

#endif
