#
# This file is part of elements.
# 
# Copyright (C) 2009-2011 William Oliveira de Lagos <william.lagos@icloud.com>
#
# Elements is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Elements is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with elements.  If not, see <http://www.gnu.org/licenses/>.
#

import platform

class Sound:
    def __init__(self):
        self.invaders = platform.load('audio')
        self.sounds = []
    def archive(self,file):
        self.sounds.append(invaders.load_sound(file))
    def play(self,namefile):
        for s in sounds:
            if namefile is s:
                invaders.play_sound(file)
    def stop_one(self,namefile):
        for s in sounds:
            if namefile is s:
                invaders.stop_sound(file)
    def stop(self):
        for s in sounds:
            invaders.stop_sound(file)

class Music:
    def __init__(self):
        pass
    
class Effects:
    def __init__(self):
        pass