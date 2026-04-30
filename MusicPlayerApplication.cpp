#include "MusicPlayerApplication.hpp"
#include "MusicPlayerFacade.hpp"
#include "managers/PlaylistManager.hpp"
#include "models/Song.hpp"

MusicPlayerApplication* MusicPlayerApplication::instance = nullptr;

void MusicPlayerApplication::createSongInLibrary(const string& title, const string& artist, const string& path) {
    Song* newSong = new Song(title, artist, path);
    songLibrary.push_back(newSong);
}

Song* MusicPlayerApplication::findSongByTitle(const string& title) {
    for (Song* s : songLibrary) {
        if (s->getTitle() == title) {
            return s;
        }
    }
    return nullptr;
}

void MusicPlayerApplication::createPlaylist(const string& playlistName) {
    PlaylistManager::getInstance()->createPlaylist(playlistName);
}

void MusicPlayerApplication::addSongToPlaylist(const string& playlistName, const string& songTitle) {
    Song* song = findSongByTitle(songTitle);
    if (!song) {
        throw runtime_error("Song \"" + songTitle + "\" not found in library.");
    }
    PlaylistManager::getInstance()->addSongToPlaylist(playlistName, song);
}

void MusicPlayerApplication::connectAudioDevice(DeviceType deviceType) {
    MusicPlayerFacade::getInstance()->connectDevice(deviceType);
}

void MusicPlayerApplication::selectPlayStrategy(PlayStrategyType strategyType) {
    MusicPlayerFacade::getInstance()->setPlayStrategy(strategyType);
}

void MusicPlayerApplication::loadPlaylist(const string& playlistName) {
    MusicPlayerFacade::getInstance()->loadPlaylist(playlistName);
}

void MusicPlayerApplication::playSingleSong(const string& songTitle) {
    Song* song = findSongByTitle(songTitle);
    if (!song) {
        throw runtime_error("Song \"" + songTitle + "\" not found.");
    }
    MusicPlayerFacade::getInstance()->playSong(song);
}

void MusicPlayerApplication::pauseCurrentSong(const string& songTitle) {
    Song* song = findSongByTitle(songTitle);
    if (!song) {
        throw runtime_error("Song \"" + songTitle + "\" not found.");
    }
    MusicPlayerFacade::getInstance()->pauseSong(song);
}

void MusicPlayerApplication::playAllTracksInPlaylist() {
    MusicPlayerFacade::getInstance()->playAllTracks();
}

void MusicPlayerApplication::playPreviousTrackInPlaylist() {
    MusicPlayerFacade::getInstance()->playPreviousTrack();
}

void MusicPlayerApplication::queueSongNext(const string& songTitle) {
    Song* song = findSongByTitle(songTitle);
    if (!song) {
        throw runtime_error("Song \"" + songTitle + "\" not found.");
    }
    MusicPlayerFacade::getInstance()->enqueueNext(song);
}
