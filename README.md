![miniRT](art/cover.bmp)

miniRT
======
by fde-capu

USAGE: `miniRT rt_file [--save [output]]`
	output is `minirt.bmp` if left blank

Navigation keys:
- `c` change camera
- `C` change camera reverse
- `r` rotate all objects 90º at self origin by camera pointer axis
- `R` rotate camera 90º (tilt)
- `t` translate all objects centrifugally
- `T` translate all objects centripetally
- `q` or `<Esc>` closes window

Bonus:
- `bonus on` activates
- `bonus off` deactivates
- `bonus x` swiches

<sub><sup>
dependent of zlib1g-dev
</sup></sub>

### Brief:
This project **miniRT** is, out of thin air, able to render full 3D graphics on a pixel-by-pixel basis.
Fully written in `C`. Matrix functions manually implemented, no external libraries.
For screen rendering, it is based on *MinilibX*, a simple X-Window (X11R6) programming API in C written by Olivier Crouzet. *MinilibX* give us the possibility of opening windows, capturing keyboard events and drawing... pixels. (More: https://github.com/42Paris/minilibx-linux).

#### Summary of specifications:
Cylinders (outside and inside), spheres (outside and inside), triangles, squares, infinite planes, lights, multicamera, camera movement and rotation and objects scaling, movement and rotation. Must deal with screen size against resolution. Must be able to save a valid `.bmp` format.

##### Sample of file `.rt`:
    R 1920 1080	# Resolution Width Height.
    A 0.2 255,255,255 # Ambient light, power, RGB color.
    c -50,0,20 0,0,0 70 # Camera position, normalized direction, focus of view. Accepts many.
    l -40,0,30 0.7 255,255,255 # Light position, power, RGB color. Accepcts many.
    pl 0,0,0 0,1.0,0 255,0,225 # Plane origin, normal, RGB color.
    sp 0,0,20 20 255,0,0 # Sphere origin, diameter, RGB color.
    sq 0,100,40 0,0,1.0 30 42,42,0 # Square origin, normal, side size, RGB color.
    cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255 # Cylinder origin, normalized orientation, diameter, height, RGB color.
    tr 10,20,10 10,10,20 20,10,10 0,0,255 # Triangle vertex, vertex, vertex, RGB color.

##### Bonus
When activating the *bonus* mode, things get weird. Do not panic, it is intentional! That is because it is designed only to show some extra features: skybox, cylinder caps, normal disruption (rainbow based on normals), and keyboard interactivity for camera and objects.

*this project is part of 42 São Paulo curriculum*

*just bragging this was the first sucessfull deliver of **miniRT** by our 42 campus*

Copyright 2020 fde-capu

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
