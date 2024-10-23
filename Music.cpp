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

    virtual void display() const = 0;

    virtual ~Song() {
        cout << "Song object destroyed.\n";
    }
};
class SpecialSong : public Song {
private:
    string genre;  
public:
    SpecialSong(string t, string a, string g) : Song(t, a), genre(g) {}

    void display() const override {
        cout << "Special Song - Title: " << title << ", Artist: " << artist << ", Genre: " << genre << endl;
    }

    ~SpecialSong() {
        cout << "SpecialSong object destroyed.\n";
    }
};

class Playlist {
private:
    vector<Song*> songs; 
public:
    void addSong(Song* song) {
        songs.push_back(song);
    }

    void displayAll() const {
        for (const auto& song : songs) {
            song->display(); 
        }
    }

    ~Playlist() {
        for (auto& song : songs) {
            delete song;  
        }
    }
};

int main() {
    Playlist myPlaylist;

    Song* specialSong1 = new SpecialSong("Special Song 1", "Artist A", "Pop");
    myPlaylist.addSong(specialSong1);

    Song* specialSong2 = new SpecialSong("Special Song 2", "Artist B", "Rock");
    myPlaylist.addSong(specialSong2);

    myPlaylist.displayAll();

    return 0;
}
