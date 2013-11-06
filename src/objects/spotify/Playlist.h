/**
The MIT License (MIT)

Copyright (c) <2013> <Moritz Schulze>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
**/

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include <memory>
#include <libspotify/api.h>

#include "../node/V8Callable.h"

#include "Track.h"

class Playlist {
friend class NodePlaylist;
friend class PlaylistCallbacks;
friend class PlaylistContainer;
public:
  Playlist(sp_playlist* _playlist, int _id);
  ~Playlist() {
    sp_playlist_release(playlist);
  };
  Playlist(const Playlist& other) : id(other.id), playlist(other.playlist), nodeObject(other.nodeObject) {
    sp_playlist_add_ref(playlist);
  }

  std::vector<std::shared_ptr<Track>> getTracks();
  virtual std::string name();
  std::string link();
private:
  int id;
  sp_playlist* playlist;
  static sp_playlist_callbacks playlistCallbacks;
  V8Callable* nodeObject;
};

#endif
