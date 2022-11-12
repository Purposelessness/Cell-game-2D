#include "KeyboardInputReaderGenerator.h"

#include "../Provider/ControlSchemeFileProvider.h"

std::shared_ptr<KeyboardInputReader>
KeyboardInputReaderGenerator::operator()() {
  ControlSchemeFileProvider provider;
  auto scheme = provider.scanScheme();
  auto keyboard_reader = std::make_shared<KeyboardInputReader>(scheme);
  return keyboard_reader;
}
