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
    Song(string t, string a) : title(t), artist(a) {}

    // Function to display the details of the song
    void display() const {
        cout << "Title: " << title << ", Artist: " << artist << endl;
    }

    // Function to get the title of the song
    string getTitle() const {
        return title;
    }
};

// Class representing a Playlist
class Playlist {
private:
    vector<Song> songs; // Private member variable to store the list of songs in the playlist

public:
    // Function to add a song to the playlist
    void addSong(const Song &song) {
        songs.push_back(song);
    }

    // Function to display all songs in the playlist
    void displayAll() const {
        for (const auto &song : songs) {
            song.display();
        }
    }
};

int main() {
    // Creating Song objects
    Song song1("Song One", "Artist A");
    Song song2("Song Two", "Artist B");

    // Creating a Playlist object
    Playlist myPlaylist;

    // Adding songs to the playlist
    myPlaylist.addSong(song1);
    myPlaylist.addSong(song2);

    // Displaying all songs in the playlist
    myPlaylist.displayAll();

    return 0;
}
