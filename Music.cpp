#include <iostream>
#include <vector>
#include <string>

using namespace std; // Declare using namespace at the top

// Class representing a Song
class Song {
private:
    string title;  // Private member variable to store the title of the song
    string artist; // Private member variable to store the artist of the song

public:
    // Constructor to initialize the Song object with a title and an artist
    Song(string t, string a) {
        this->title = t;
        this->artist = a;
    }

    // Function to display the details of the song
    void display() const {
        cout << "Title: " << title << ", Artist: " << artist << endl;
    }

    // Function to get the title of the song
    string getTitle() const {
        return this->title;
    }
};

// Class representing a Playlist
class Playlist {
private:
    vector<Song> songs; // Private member variable to store the list of songs in the playlist

public:
    // Function to add a song to the playlist
    void addSong(const Song &song) {
        this->songs.push_back(song);
    }

    // Function to display all songs in the playlist
    void displayAll() const {
        for (const auto &song : this->songs) {
            song.display();
        }
    }
};

int main() {
    // Creating an array of pointers to Song objects
    Song* songArray[] = {
        new Song("Song One", "Artist A"),
        new Song("Song Two", "Artist B"),
        new Song("Song Three", "Artist C")
    };

    // Creating a Playlist object
    Playlist* myPlaylist = new Playlist();

    // Adding songs from the array to the playlist
    for (Song* song : songArray) {
        myPlaylist->addSong(*song);
    }

    // Displaying all songs in the playlist
    myPlaylist->displayAll();

    // Deleting dynamically allocated Song objects
    for (Song* song : songArray) {
        delete song;
    }

    // Deleting the dynamically allocated Playlist object
    delete myPlaylist;

    return 0;
}
