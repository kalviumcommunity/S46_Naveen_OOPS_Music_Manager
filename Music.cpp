#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Song {
protected:
    string title;   
    string artist;

public:
    Song(string t, string a) : title(t), artist(a) {}

    virtual void display() const {
        cout << "Title: " << title << ", Artist: " << artist << endl;
    }
};
class SpecialSong : public Song {
private:
    string genre;
public:
    SpecialSong(string t, string a, string g) : Song(t, a), genre(g) {}

    void display() const override {
        cout << "Title: " << title << ", Artist: " << artist << ", Genre: " << genre << endl;
    }
};

class Playlist {
private:
    vector<Song*> songs; 

public:
    void addSong(Song &song) {
        songs.push_back(&song);
    }

    void addSong(string title, string artist) {
        Song* newSong = new Song(title, artist);
        songs.push_back(newSong);
    }

    void displayAll() const {
        for (const auto &song : songs) {
            song->display(); 
        }
    }
};

int main() {
    Song song1("Song One", "Artist A");
    SpecialSong specialSong1("Special Song", "Artist B", "Pop");

    Playlist myPlaylist;

    myPlaylist.addSong(song1);  
    myPlaylist.addSong(specialSong1);  

    myPlaylist.addSong("Song Two", "Artist C");

    myPlaylist.displayAll();

    return 0;
}
