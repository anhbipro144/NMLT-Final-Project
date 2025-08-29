#ifndef ASCII_HPP
#define ASCII_HPP

#include "ftxui/component/component_base.hpp"
#include <string>

#define FONT_LIST                                                              \
  X(_1Row, "1Row.flf")                                                         \
  X(_3D, "3-D.flf")                                                            \
  X(_3DASCII, "3D-ASCII.flf")                                                  \
  X(_3d, "3d.flf")                                                             \
  X(_3d_diagonal, "3d_diagonal.flf")                                           \
  X(_3DDiagonal, "3D Diagonal.flf")                                            \
  X(_3x5, "3x5.flf")                                                           \
  X(_4Max, "4Max.flf")                                                         \
  X(_5lineoblique, "5lineoblique.flf")                                         \
  X(_5LineOblique, "5 Line Oblique.flf")                                       \
  X(Acrobatic, "Acrobatic.flf")                                                \
  X(Alligator, "Alligator.flf")                                                \
  X(Alligator2, "Alligator2.flf")                                              \
  X(alligator3, "alligator3.flf")                                              \
  X(Alpha, "Alpha.flf")                                                        \
  X(Alphabet, "Alphabet.flf")                                                  \
  X(AMC3Line, "AMC 3 Line.flf")                                                \
  X(amc3line, "amc3line.flf")                                                  \
  X(amc3liv1, "amc3liv1.flf")                                                  \
  X(AMCAAA01, "AMC AAA01.flf")                                                 \
  X(amcaaa01, "amcaaa01.flf")                                                  \
  X(amcneko, "amcneko.flf")                                                    \
  X(AMCNeko, "AMC Neko.flf")                                                   \
  X(amcrazo2, "amcrazo2.flf")                                                  \
  X(AMCRazor, "AMC Razor.flf")                                                 \
  X(amcrazor, "amcrazor.flf")                                                  \
  X(AMCRazor2, "AMC Razor2.flf")                                               \
  X(amcslash, "amcslash.flf")                                                  \
  X(AMCSlash, "AMC Slash.flf")                                                 \
  X(amcslder, "amcslder.flf")                                                  \
  X(AMCSlider, "AMC Slider.flf")                                               \
  X(amcthin, "amcthin.flf")                                                    \
  X(AMCThin, "AMC Thin.flf")                                                   \
  X(amctubes, "amctubes.flf")                                                  \
  X(AMCTubes, "AMC Tubes.flf")                                                 \
  X(amcun1, "amcun1.flf")                                                      \
  X(AMCUntitled, "AMC Untitled.flf")                                           \
  X(ANSIRegular, "ANSI Regular.flf")                                           \
  X(ANSIShadow, "ANSI Shadow.flf")                                             \
  X(Arrows, "Arrows.flf")                                                      \
  X(ascii_new_roman, "ascii_new_roman.flf")                                    \
  X(ASCIINewRoman, "ASCII New Roman.flf")                                      \
  X(Avatar, "Avatar.flf")                                                      \
  X(B1FF, "B1FF.flf")                                                          \
  X(Banner, "Banner.flf")                                                      \
  X(Banner3D, "Banner3-D.flf")                                                 \
  X(Banner3, "Banner3.flf")                                                    \
  X(Banner4, "Banner4.flf")                                                    \
  X(Barbwire, "Barbwire.flf")                                                  \
  X(Basic, "Basic.flf")                                                        \
  X(Bear, "Bear.flf")                                                          \
  X(Bell, "Bell.flf")                                                          \
  X(Benjamin, "Benjamin.flf")                                                  \
  X(Big, "Big.flf")                                                            \
  X(bigchief, "bigchief.flf")                                                  \
  X(BigChief, "Big Chief.flf")                                                 \
  X(Bigfig, "Bigfig.flf")                                                      \
  X(BigMoneyNE, "Big Money-ne.flf")                                            \
  X(BigMoneyNW, "Big Money-nw.flf")                                            \
  X(BigMoneySE, "Big Money-se.flf")                                            \
  X(BigMoneySW, "Big Money-sw.flf")                                            \
  X(Binary, "Binary.flf")                                                      \
  X(Block, "Block.flf")                                                        \
  X(Blocks, "Blocks.flf")                                                      \
  X(Bloody, "Bloody.flf")                                                      \
  X(Bolger, "Bolger.flf")                                                      \
  X(Braced, "Braced.flf")                                                      \
  X(Bright, "Bright.flf")                                                      \
  X(Broadway, "Broadway.flf")                                                  \
  X(broadway_kb, "broadway_kb.flf")                                            \
  X(BroadwayKB, "Broadway KB.flf")                                             \
  X(Bubble, "Bubble.flf")                                                      \
  X(Bulbhead, "Bulbhead.flf")                                                  \
  X(calgphy2, "calgphy2.flf")                                                  \
  X(Caligraphy, "Caligraphy.flf")                                              \
  X(Caligraphy2, "Caligraphy2.flf")                                            \
  X(CalvinS, "Calvin S.flf")                                                   \
  X(Cards, "Cards.flf")                                                        \
  X(Catwalk, "Catwalk.flf")                                                    \
  X(Chiseled, "Chiseled.flf")                                                  \
  X(Chunky, "Chunky.flf")                                                      \
  X(Coinstak, "Coinstak.flf")                                                  \
  X(Cola, "Cola.flf")                                                          \
  X(Colossal, "Colossal.flf")                                                  \
  X(Computer, "Computer.flf")                                                  \
  X(Contessa, "Contessa.flf")                                                  \
  X(Contrast, "Contrast.flf")                                                  \
  X(cosmic, "cosmic.flf")                                                      \
  X(Cosmike, "Cosmike.flf")                                                    \
  X(Crawford, "Crawford.flf")                                                  \
  X(Crawford2, "Crawford2.flf")                                                \
  X(Crazy, "Crazy.flf")                                                        \
  X(Cricket, "Cricket.flf")                                                    \
  X(Cursive, "Cursive.flf")                                                    \
  X(Cyberlarge, "Cyberlarge.flf")                                              \
  X(Cybermedium, "Cybermedium.flf")                                            \
  X(Cybersmall, "Cybersmall.flf")                                              \
  X(Cygnet, "Cygnet.flf")                                                      \
  X(DANC4, "DANC4.flf")                                                        \
  X(DancingFont, "Dancing Font.flf")                                           \
  X(dancingfont, "dancingfont.flf")                                            \
  X(DefLeppard, "Def Leppard.flf")                                             \
  X(defleppard, "defleppard.flf")                                              \
  X(DeltaCorpsPriest1, "Delta Corps Priest 1.flf")                             \
  X(Diamond, "Diamond.flf")                                                    \
  X(dietcola, "dietcola.flf")                                                  \
  X(DietCola, "Diet Cola.flf")                                                 \
  X(Digital, "Digital.flf")                                                    \
  X(Doh, "Doh.flf")                                                            \
  X(Doom, "Doom.flf")                                                          \
  X(DOSRebel, "DOS Rebel.flf")                                                 \
  X(dosrebel, "dosrebel.flf")                                                  \
  X(DotMatrix, "Dot Matrix.flf")                                               \
  X(dotmatrix, "dotmatrix.flf")                                                \
  X(Double, "Double.flf")                                                      \
  X(doubleshorts, "doubleshorts.flf")                                          \
  X(DoubleShorts, "Double Shorts.flf")                                         \
  X(drpepper, "drpepper.flf")                                                  \
  X(DrPepper, "Dr Pepper.flf")                                                 \
  X(DWhistled, "DWhistled.flf")                                                \
  X(EftiChess, "Efti Chess.flf")                                               \
  X(eftichess, "eftichess.flf")                                                \
  X(eftifont, "eftifont.flf")                                                  \
  X(EftiFont, "Efti Font.flf")                                                 \
  X(EftiItalic, "Efti Italic.flf")                                             \
  X(eftipiti, "eftipiti.flf")                                                  \
  X(EftiPiti, "Efti Piti.flf")                                                 \
  X(EftiRobot, "Efti Robot.flf")                                               \
  X(eftirobot, "eftirobot.flf")                                                \
  X(EftiWall, "Efti Wall.flf")                                                 \
  X(eftiwall, "eftiwall.flf")                                                  \
  X(EftiWater, "Efti Water.flf")                                               \
  X(eftiwater, "eftiwater.flf")                                                \
  X(Electronic, "Electronic.flf")                                              \
  X(Elite, "Elite.flf")                                                        \
  X(Epic, "Epic.flf")                                                          \
  X(Fender, "Fender.flf")                                                      \
  X(Filter, "Filter.flf")                                                      \
  X(fire_fontk, "fire_font-k.flf")                                             \
  X(FireFontK, "Fire Font-k.flf")                                              \
  X(fire_fonts, "fire_font-s.flf")                                             \
  X(FireFontS, "Fire Font-s.flf")                                              \
  X(Flipped, "Flipped.flf")                                                    \
  X(flowerpower, "flowerpower.flf")                                            \
  X(FlowerPower, "Flower Power.flf")                                           \
  X(FunFace, "Fun Face.flf")                                                   \
  X(funface, "funface.flf")                                                    \
  X(FunFaces, "Fun Faces.flf")                                                 \
  X(funfaces, "funfaces.flf")                                                  \
  X(Fuzzy, "Fuzzy.flf")                                                        \
  X(Georgi16, "Georgi16.flf")                                                  \
  X(Georgia11, "Georgia11.flf")                                                \
  X(Ghost, "Ghost.flf")                                                        \
  X(Ghoulish, "Ghoulish.flf")                                                  \
  X(Glenyn, "Glenyn.flf")                                                      \
  X(Goofy, "Goofy.flf")                                                        \
  X(Gothic, "Gothic.flf")                                                      \
  X(Graceful, "Graceful.flf")                                                  \
  X(Gradient, "Gradient.flf")                                                  \
  X(Graffiti, "Graffiti.flf")                                                  \
  X(Greek, "Greek.flf")                                                        \
  X(heart_left, "heart_left.flf")                                              \
  X(HeartLeft, "Heart Left.flf")                                               \
  X(heart_right, "heart_right.flf")                                            \
  X(HeartRight, "Heart Right.flf")                                             \
  X(Henry3D, "Henry 3D.flf")                                                   \
  X(henry3d, "henry3d.flf")                                                    \
  X(Hex, "Hex.flf")                                                            \
  X(Hieroglyphs, "Hieroglyphs.flf")                                            \
  X(Hollywood, "Hollywood.flf")                                                \
  X(HorizontalLeft, "Horizontal Left.flf")                                     \
  X(horizontalleft, "horizontalleft.flf")                                      \
  X(HorizontalRight, "Horizontal Right.flf")                                   \
  X(horizontalright, "horizontalright.flf")                                    \
  X(ICL1900, "ICL-1900.flf")                                                   \
  X(Impossible, "Impossible.flf")                                              \
  X(Invita, "Invita.flf")                                                      \
  X(Isometric1, "Isometric1.flf")                                              \
  X(Isometric2, "Isometric2.flf")                                              \
  X(Isometric3, "Isometric3.flf")                                              \
  X(Isometric4, "Isometric4.flf")                                              \
  X(Italic, "Italic.flf")                                                      \
  X(Ivrit, "Ivrit.flf")                                                        \
  X(Jacky, "Jacky.flf")                                                        \
  X(Jazmine, "Jazmine.flf")                                                    \
  X(Katakana, "Katakana.flf")                                                  \
  X(Kban, "Kban.flf")                                                          \
  X(Keyboard, "Keyboard.flf")                                                  \
  X(Knob, "Knob.flf")                                                          \
  X(Konto, "Konto.flf")                                                        \
  X(kontoslant, "kontoslant.flf")                                              \
  X(KontoSlant, "Konto Slant.flf")                                             \
  X(larry3d, "larry3d.flf")                                                    \
  X(Larry3D, "Larry 3D.flf")                                                   \
  X(Larry3D2, "Larry 3D 2.flf")                                                \
  X(maxfour, "Maxfour.flf")                                                    \
  X(maxiwi, "maxiwi.flf")                                                      \
  X(Merlin1, "Merlin1.flf")                                                    \
  X(Merlin2, "Merlin2.flf")                                                    \
  X(Mike, "Mike.flf")                                                          \
  X(Mini, "Mini.flf")                                                          \
  X(miniwi, "miniwi.flf")                                                      \
  X(Mnemonic, "Mnemonic.flf")                                                  \
  X(Morse, "Morse.flf")                                                        \
  X(Morse2, "Morse2.flf")                                                      \
  X(Modular, "Modular.flf")                                                    \
  X(Mirror, "Mirror.flf")                                                      \
  X(NancyjFancy, "Nancyj-Fancy.flf")                                           \
  X(NancyjImproved, "Nancyj-Improved.flf")                                     \
  X(NancyjUnderlined, "Nancyj-Underlined.flf")                                 \
  X(Nancyj, "Nancyj.flf")                                                      \
  X(Nipples, "Nipples.flf")                                                    \
  X(NScript, "NScript.flf")                                                    \
  X(NTGreek, "NT Greek.flf")                                                   \
  X(NVScript, "NV Script.flf")                                                 \
  X(O8, "O8.flf")                                                              \
  X(Octal, "Octal.flf")                                                        \
  X(Ogre, "Ogre.flf")                                                          \
  X(oldbanner, "oldbanner.flf")                                                \
  X(OldBanner, "Old Banner.flf")                                               \
  X(OS2, "OS2.flf")                                                            \
  X(PatorjksCheese, "Patorjk's Cheese.flf")                                    \
  X(PatorjkHeX, "Patorjk-HeX.flf")                                             \
  X(Pawp, "Pawp.flf")                                                          \
  X(Peaks, "Peaks.flf")                                                        \
  X(PeaksSlant, "Peaks Slant.flf")                                             \
  X(peaksslant, "peaksslant.flf")                                              \
  X(Pebbles, "Pebbles.flf")                                                    \
  X(Pepper, "Pepper.flf")                                                      \
  X(Poison, "Poison.flf")                                                      \
  X(Puffy, "Puffy.flf")                                                        \
  X(Puzzle, "Puzzle.flf")                                                      \
  X(Pyramid, "Pyramid.flf")                                                    \
  X(Rammstein, "Rammstein.flf")                                                \
  X(Rectangles, "Rectangles.flf")                                              \
  X(red_phoenix, "red_phoenix.flf")                                            \
  X(RedPhoenix, "Red Phoenix.flf")                                             \
  X(Relief, "Relief.flf")                                                      \
  X(Relief2, "Relief2.flf")                                                    \
  X(rev, "rev.flf")                                                            \
  X(Reverse, "Reverse.flf")                                                    \
  X(Roman, "Roman.flf")                                                        \
  X(Rot13, "Rot13.flf")                                                        \
  X(Rotated, "Rotated.flf")                                                    \
  X(Rounded, "Rounded.flf")                                                    \
  X(RowanCap, "Rowan Cap.flf")                                                 \
  X(rowancap, "rowancap.flf")                                                  \
  X(Rozzo, "Rozzo.flf")                                                        \
  X(Runic, "Runic.flf")                                                        \
  X(Runyc, "Runyc.flf")                                                        \
  X(s_relief, "s-relief.flf")                                                  \
  X(SantaClara, "Santa Clara.flf")                                             \
  X(santaclara, "santaclara.flf")                                              \
  X(SBlood, "S Blood.flf")                                                     \
  X(sblood, "sblood.flf")                                                      \
  X(Script, "Script.flf")                                                      \
  X(Serifcap, "Serifcap.flf")                                                  \
  X(Shadow, "Shadow.flf")                                                      \
  X(Shimrod, "Shimrod.flf")                                                    \
  X(Short, "Short.flf")                                                        \
  X(Slant, "Slant.flf")                                                        \
  X(SlantRelief, "Slant Relief.flf")                                           \
  X(Slide, "Slide.flf")                                                        \
  X(SLScript, "SL Script.flf")                                                 \
  X(slscript, "slscript.flf")                                                  \
  X(Small, "Small.flf")                                                        \
  X(smallcaps, "smallcaps.flf")                                                \
  X(SmallCaps, "Small Caps.flf")                                               \
  X(SmallIsometric1, "Small Isometric1.flf")                                   \
  X(smisome1, "smisome1.flf")                                                  \
  X(SmallKeyboard, "Small Keyboard.flf")                                       \
  X(smkeyboard, "smkeyboard.flf")                                              \
  X(SmallPoison, "Small Poison.flf")                                           \
  X(smpoison, "smpoison.flf")                                                  \
  X(smscript, "smscript.flf")                                                  \
  X(smshadow, "smshadow.flf")                                                  \
  X(smslant, "smslant.flf")                                                    \
  X(smtengwar, "smtengwar.flf")                                                \
  X(Soft, "Soft.flf")                                                          \
  X(Speed, "Speed.flf")                                                        \
  X(Spliff, "Spliff.flf")                                                      \
  X(Stacey, "Stacey.flf")                                                      \
  X(Stampate, "Stampate.flf")                                                  \
  X(Stampatello, "Stampatello.flf")                                            \
  X(Standard, "Standard.flf")                                                  \
  X(starstrips, "starstrips.flf")                                              \
  X(StarStrips, "Star Strips.flf")                                             \
  X(starwars, "starwars.flf")                                                  \
  X(StarWars, "Star Wars.flf")                                                 \
  X(Stellar, "Stellar.flf")                                                    \
  X(Stforek, "Stforek.flf")                                                    \
  X(StickLetters, "Stick Letters.flf")                                         \
  X(Stop, "Stop.flf")                                                          \
  X(Straight, "Straight.flf")                                                  \
  X(StrongerThanAll, "Stronger Than All.flf")                                  \
  X(SubZero, "Sub-Zero.flf")                                                   \
  X(swampland, "swampland.flf")                                                \
  X(SwampLand, "Swamp Land.flf")                                               \
  X(Swan, "Swan.flf")                                                          \
  X(Sweet, "Sweet.flf")                                                        \
  X(Tanja, "Tanja.flf")                                                        \
  X(Tengwar, "Tengwar.flf")                                                    \
  X(Term, "Term.flf")                                                          \
  X(Test1, "Test1.flf")                                                        \
  X(TheEdge, "The Edge.flf")                                                   \
  X(Thick, "Thick.flf")                                                        \
  X(Thin, "Thin.flf")                                                          \
  X(THIS, "THIS.flf")                                                          \
  X(Thorned, "Thorned.flf")                                                    \
  X(Threepoint, "Threepoint.flf")                                              \
  X(ThreePoint, "Three Point.flf")                                             \
  X(Ticks, "Ticks.flf")                                                        \
  X(ticksslant, "ticksslant.flf")                                              \
  X(Tiles, "Tiles.flf")                                                        \
  X(TinkerToy, "Tinker-Toy.flf")                                               \
  X(Tombstone, "Tombstone.flf")                                                \
  X(Train, "Train.flf")                                                        \
  X(Trek, "Trek.flf")                                                          \
  X(Tsalagi, "Tsalagi.flf")                                                    \
  X(Tubular, "Tubular.flf")                                                    \
  X(Twisted, "Twisted.flf")                                                    \
  X(twopoint, "twopoint.flf")                                                  \
  X(TwoPoint, "Two Point.flf")                                                 \
  X(Univers, "Univers.flf")                                                    \
  X(usaflag, "usaflag.flf")                                                    \
  X(Varsity, "Varsity.flf")                                                    \
  X(Wavy, "Wavy.flf")                                                          \
  X(Weird, "Weird.flf")                                                        \
  X(WetLetter, "Wet Letter.flf")                                               \
  X(Whimsy, "Whimsy.flf")                                                      \
  X(Wow, "Wow.flf")

enum class Font {
#define X(sym, file) sym,
  FONT_LIST
#undef X
};

static constexpr struct {
  Font f;
  const char *name;
}

font_files[] = {
#define X(sym, file) {Font::sym, file},
    FONT_LIST
#undef X
};

std::string make_ascii(const std::string &text, Font font = Font::Standard);

std::vector<std::string> split_lines(std::string const &s);

ftxui::Component AsciiArt(std::string str);

ftxui::Element AsciiArtElement(std::string str);

#endif
