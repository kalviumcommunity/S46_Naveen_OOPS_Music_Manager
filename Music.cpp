#include <iostream>
#include <vector>
#include <string>

using namespace std; // Declare using namespace at the top

// Class representing a Song
class Song {
private:
    string title;  // Private member variable to store the title of the song
    string artist; // Private member variable to store the artist of the song

    static int songCount; // Static variable to keep track of the number of Song objects

public:
    // Constructor to initialize the Song object with a title and an artist
    Song(string t, string a) : title(t), artist(a) {
        songCount++;
    }

    // Destructor to decrement songCount when a Song object is destroyed
    ~Song() {
        songCount--;
    }

    // Accessor for title
    string getTitle() const {
        return title;
    }

    // Mutator for title
    void setTitle(const string &t) {
        title = t;
    }

    // Accessor for artist
    string getArtist() const {
        return artist;
    }

    // Mutator for artist
    void setArtist(const string &a) {
        artist = a;
    }

    // Static function to get the number of Song objects created
    static int getSongCount() {
        return songCount;
    }

    // Function to display the details of the song
    void display() const {
        cout << "Title: " << title << ", Artist: " << artist << endl;
    }
};

// Initialize the static variable
int Song::songCount = 0;

// Class representing a Playlist
class Playlist {
private:
    vector<Song> songs; // Private member variable to store the list of songs in the playlist
    static int playlistCount; // Static variable to keep track of the number of Playlist objects

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
    // Creating Song objects with dynamic memory allocation
    Song* song1 = new Song("Song One", "Artist A");
    Song* song2 = new Song("Song Two", "Artist B");

    // Displaying song details
    song1->display();
    song2->display();

    // Using mutator to change song details
    song1->setTitle("Updated Song One");
    song1->setArtist("Updated Artist A");
    song1->display(); // Display updated details

    // Creating a Playlist object
    Playlist* myPlaylist = new Playlist();
    myPlaylist->addSong(*song1);
    myPlaylist->addSong(*song2);

    // Displaying all songs in the playlist
    myPlaylist->displayAll();

    // Displaying static variable values
    cout << "Number of Song objects: " << Song::getSongCount() << endl;
    cout << "Number of Playlist objects: " << Playlist::getPlaylistCount() << endl;

    // Deleting dynamically allocated Song objects
    delete song1;
    delete song2;
    delete myPlaylist;

    // Displaying static variable values after deletion
    cout << "Number of Song objects after deletion: " << Song::getSongCount() << endl;
    cout << "Number of Playlist objects after deletion: " << Playlist::getPlaylistCount() << endl;

    return 0;
}
