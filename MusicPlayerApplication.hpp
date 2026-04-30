#pragma once
#include <vector>
#include <string>
#include <stdexcept>
#include "enums/DeviceType.hpp"
#include "enums/PlayStrategyType.hpp"

class MusicPlayerFacade;
class PlaylistManager;
class Song;

using namespace std;

class MusicPlayerApplication {
private:
    static MusicPlayerApplication* instance;
    vector<Song*> songLibrary;
    MusicPlayerApplication() {}

public:
    static MusicPlayerApplication* getInstance() {
        if (!instance) {
            instance = new MusicPlayerApplication();
        }
        return instance;
    }

    void createSongInLibrary(const string& title, const string& artist,
                                const string& path);
    Song* findSongByTitle(const string& title);
    void createPlaylist(const string& playlistName);
    void addSongToPlaylist(const string& playlistName,
                            const string& songTitle);
    void connectAudioDevice(DeviceType deviceType);
    void selectPlayStrategy(PlayStrategyType strategyType);
    void loadPlaylist(const string& playlistName);
    void playSingleSong(const string& songTitle);
    void pauseCurrentSong(const string& songTitle);
    void playAllTracksInPlaylist();
    void playPreviousTrackInPlaylist();
    void queueSongNext(const string& songTitle);
};