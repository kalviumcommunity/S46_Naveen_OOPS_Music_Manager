#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract base class representing a generic Song
class Song {
protected:
    string title;
    string artist;

public:
    // Constructor to initialize title and artist
    Song(string t, string a) : title(t), artist(a) {}

    // Pure virtual function to enforce specific implementation in derived classes
    virtual void display() const = 0;

    // Virtual destructor to allow proper cleanup
    virtual ~Song() {
        cout << "Song object destroyed.\n";
    }
};

// Derived class representing a Special Song with an additional genre attribute
class SpecialSong : public Song {
private:
    string genre; // Unique attribute for SpecialSong

public:
    // Constructor to initialize title, artist, and genre
    SpecialSong(string t, string a, string g) : Song(t, a), genre(g) {}

    // Override the display function to show SpecialSong details
    void display() const override {
        cout << "Special Song - Title: " << title << ", Artist: " << artist << ", Genre: " << genre << endl;
    }

    // Destructor to clean up resources
    ~SpecialSong() {
        cout << "SpecialSong object destroyed.\n";
    }
};

// Class to manage a collection of songs (Playlist)
class Playlist {
private:
    vector<Song*> songs; // Stores pointers to Song objects

public:
    // Add a new song to the playlist
    void addSong(Song* song) {
        songs.push_back(song);
    }

    // Display details of all songs in the playlist
    void displayAll() const {
        for (const auto& song : songs) {
            song->display();
        }
    }

    // Destructor to clean up dynamically allocated memory
    ~Playlist() {
        for (auto& song : songs) {
            delete song; // Clean up each song
        }
        cout << "Playlist cleared.\n";
    }
};

int main() {
    // Create a playlist object
    Playlist myPlaylist;

    // Dynamically allocate and add songs to the playlist
    Song* specialSong1 = new SpecialSong("Special Song 1", "Artist A", "Pop");
    myPlaylist.addSong(specialSong1);

    Song* specialSong2 = new SpecialSong("Special Song 2", "Artist B", "Rock");
    myPlaylist.addSong(specialSong2);

    // Display all songs in the playlist
    myPlaylist.displayAll();

    // The destructor will automatically clean up when the playlist goes out of scope
    return 0;
}
