#ifndef filter_hpp
#define filter_hpp

#include "book.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

struct ModalState {
  std::shared_ptr<bool> model_shown;
  ftxui::ComponentDecorator Modal;
};

ModalState createAddModal(std::shared_ptr<std::vector<Book>> books);
#endif
