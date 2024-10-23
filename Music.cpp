#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Media {
protected:
    string title;  
public:
   
    Media(string t) : title(t) {}

  
    virtual void display() const {
        cout << "Title: " << title << endl;
    }
};

class Song : public Media {
private:
    string artist; 
    static int songCount;

public:
    Song(string t, string a) : Media(t), artist(a) {
        songCount++;
    }

    ~Song() {
        songCount--;
    }

  
    string getArtist() const {
        return artist;
    }

    void setArtist(const string &a) {
        artist = a;
    }
    static int getSongCount() {
        return songCount;
    }

    void display() const override {
        cout << "Song - Title: " << title << ", Artist: " << artist << endl;
    }
};

int Song::songCount = 0;

class Podcast : public Media {
private:
    string host; 

public:
    Podcast(string t, string h) : Media(t), host(h) {}

    void display() const override {
        cout << "Podcast - Title: " << title << ", Host: " << host << endl;
    }
};
class Playlist {
private:
    vector<Media*> mediaList;
    static int playlistCount; 

public:
    Playlist() {
        playlistCount++;
    }

    ~Playlist() {
        playlistCount--;
    }

    void addMedia(Media* media) {
        this->mediaList.push_back(media);
    }

    void displayAll() const {
        for (const auto &media : this->mediaList) {
            media->display(); 
        }
    }
    static int getPlaylistCount() {
        return playlistCount;
    }
};

int Playlist::playlistCount = 0;

int main() {
    Song* song1 = new Song("Song One", "Artist A");
    Song* song2 = new Song("Song Two", "Artist B");

    Podcast* podcast1 = new Podcast("Podcast One", "Host A");

    song1->display();
    song2->display();
    podcast1->display();

    Playlist* myPlaylist = new Playlist();
    myPlaylist->addMedia(song1);
    myPlaylist->addMedia(song2);
    myPlaylist->addMedia(podcast1);

    myPlaylist->displayAll();

    cout << "Number of Song objects: " << Song::getSongCount() << endl;
    cout << "Number of Playlist objects: " << Playlist::getPlaylistCount() << endl;

    delete song1;
    delete song2;
    delete podcast1;
    delete myPlaylist;

    return 0;
}
