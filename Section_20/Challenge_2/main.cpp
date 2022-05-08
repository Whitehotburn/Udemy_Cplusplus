// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <iterator>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "D - Display the current playlist" << std::endl;
    std::cout << "L - Play Last Song" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function displays
    // Playing: followed by the song that is playing
   
    std::cout << "Playing:" << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function displays the current playlist
    // and the current song playing.
    std::cout << std::endl;

    for (const auto &song: playlist) {
        std::cout << song << std::endl;
    }
    std::cout << "\nCurrent song:" << std::endl;
    std::cout << current_song << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroon 5",                  4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    char selection{};
    
    do {
        display_menu();
        std::cin >> selection;
        selection = std::toupper(selection);

        if (selection == 'F') {
            std::cout << "*** Playing first song ***" << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);

        } else if (selection == 'N') {
            std::cout << "*** Playing next song ***" << std::endl;
            // std::advance(current_song, 1); // same as below
            current_song++;
            if (current_song == playlist.end())
                current_song = playlist.begin();

            play_current_song(*current_song);

        } else if (selection == 'P') {
            std::cout << "*** Playing next song ***" << std::endl;
            if (current_song == playlist.begin()) {
                std::cout << "*** Wrapping to end of playlist ***" << std::endl;
                current_song = playlist.end();
            }
            current_song--;
            play_current_song(*current_song);

        } else if (selection == 'A') {
            std::cout << "Adding and playing new song" << std::endl;

            std::string new_song_name, new_artist;
            int new_rating{};

            std::cout << "Enter song name: ";
            std::cin.ignore();
            std::getline(std::cin, new_song_name);

            std::cout << "Enter song artist: ";
            std::getline(std::cin, new_artist);

            std::cout << "Enter your rating (1-5): ";
            std::cin >> new_rating;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            auto it = std::find(playlist.begin(), playlist.end(), *current_song);
                if (it != playlist.end())
                    playlist.emplace(it, new_song_name, new_artist, new_rating);
            
            current_song--;
            play_current_song(*current_song);

        } else if (selection == 'D') {
            display_playlist(playlist, *current_song);

        } else if (selection == 'L') {
            current_song = playlist.end();
            play_current_song(*current_song);

        }
    }
    while (selection != 'q' && selection != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}