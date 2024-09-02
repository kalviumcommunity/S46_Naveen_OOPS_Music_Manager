#include <iostream>
#include <vector>
#include <string>

using namespace std; // Declare using namespace at the top

// Class representing a Song
class Song {
private:
    string title;  // Private member variable to store the title of the song
    string artist; // Private member variable to store the artist of the song

    // Static variables to keep track of the number of Song objects
    static int songCount;
    
public:
    // Constructor to initialize the Song object with a title and an artist
    Song(string t, string a) : title(t), artist(a) {
        // Increment songCount every time a new Song object is created
        songCount++;
    }

    // Destructor to decrement songCount when a Song object is destroyed
    ~Song() {
        songCount--;
    }

    // Function to display the details of the song
    void display() const {
        cout << "Title: " << title << ", Artist: " << artist << endl;
    }

    // Function to get the title of the song
    string getTitle() const {
        return this->title;
    }

    // Static function to get the number of Song objects created
    static int getSongCount() {
        return songCount;
    }
};

// Initialize the static variable
int Song::songCount = 0;

// Class representing a Playlist
class Playlist {
private:
    vector<Song> songs; // Private member variable to store the list of songs in the playlist

    // Static variable to keep track of the number of Playlist objects
    static int playlistCount;

public:
    // Constructor to initialize the Playlist object and increment playlistCount
    Playlist() {
        playlistCount++;
    }

    // Destructor to decrement playlistCount when a Playlist object is destroyed
    ~Playlist() {
        playlistCount--;
    }

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

    // Static function to get the number of Playlist objects created
    static int getPlaylistCount() {
        return playlistCount;
    }
};

// Initialize the static variable
int Playlist::playlistCount = 0;

int main() {
    // Creating an array of pointers to Song objects
    Song* songArray[] = {
        new Song("Song One", "Artist A"),
        new Song("Song Two", "Artist B"),
        new Song("Song Three", "Artist C")
    };

    // Creating Playlist objects
    Playlist* myPlaylist = new Playlist();
    Playlist* anotherPlaylist = new Playlist();

    // Adding songs from the array to the playlist
    for (Song* song : songArray) {
        myPlaylist->addSong(*song);
    }

    // Displaying all songs in the playlist
    myPlaylist->displayAll();

    // Displaying static variable values
    cout << "Number of Song objects: " << Song::getSongCount() << endl;
    cout << "Number of Playlist objects: " << Playlist::getPlaylistCount() << endl;

    // Deleting dynamically allocated Song objects
    for (Song* song : songArray) {
        delete song;
    }

    // Deleting dynamically allocated Playlist objects
    delete myPlaylist;
    delete anotherPlaylist;

    // Displaying static variable values after deletion
    cout << "Number of Song objects after deletion: " << Song::getSongCount() << endl;
    cout << "Number of Playlist objects after deletion: " << Playlist::getPlaylistCount() << endl;

    return 0;
}
