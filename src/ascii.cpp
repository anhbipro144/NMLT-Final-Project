#include "ascii.hpp"
#include "ftxui/component/component.hpp"
#include "libfiglet.hpp"
#include <ftxui/dom/node.hpp>
#include <string>

using namespace srilakshmikanthanp::libfiglet;

std::string font_to_filename(Font f) {
  for (auto &p : font_files) {
    if (p.f == f)
      return p.name;
  }
  throw std::out_of_range("Unknown Font");
}

std::string make_ascii(const std::string &text, Font font) {
  std::string filename = font_to_filename(font);

  std::string path = "../build/_deps/libfiglet_src-src/dist/fonts/" + filename;

  figlet renderer(flf_font::make_shared(path), smushed::make_shared());
  return renderer(text);
}

std::vector<std::string> split_lines(std::string const &s) {
  std::vector<std::string> out;
  std::string line;
  std::istringstream in(s);
  while (std::getline(in, line))
    out.push_back(line);
  return out;
}

ftxui::Component AsciiArt(std::string str) {
  auto lines = split_lines(str);
  return ftxui::Renderer(
      [str] { return AsciiArtElement(str) | ftxui::center; });
}

ftxui::Element AsciiArtElement(std::string ascii_str) {
  std::vector<std::string> lines = split_lines(ascii_str);

  ftxui::Elements elems;
  for (auto const &l : lines)
    elems.push_back(ftxui::text(l));
  return vbox(elems);
}
