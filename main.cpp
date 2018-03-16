#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Audio.hpp>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  if (argc < 2) {
    std::cerr << "need a path to sound file\n";
    return -1;
  }

  sf::SoundBuffer buffer;
  if (!buffer.loadFromFile(argv[1])) {
    std::cerr << "load file failed\n";
    return -1;
  }

  sf::Sound sound;
  sound.setBuffer(buffer);
  sound.play();
  while(sound.getStatus() != sf::SoundSource::Stopped) {
    std::this_thread::sleep_for(1s);
  }
}
