<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/Fractal_Explorer.png" width="100%" alt="Sand Box">
</p>

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/1_Description.png" width="100%" alt="Description">
</p>

This software is a mathematical simulation that represents a <a href="https://en.wikipedia.org/wiki/Fractal">fractal</a>.
A fractal is a mathematical object with a similar structure at all scales.
In particular, you can zoom in to infinity and see the same patterns.
This software lets you visualize two very specific fractals and move inside to observe them.

<img src="https://github.com/maxencebonamy/Sand-Box/blob/main/assets/ice.png" alt="ice" height="24px" align="top"> **Ice:** like wood or stone, ice is not subject to gravity. And like snow, it melts after a certain time, turning into water.

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/2_Get_Started.png" width="100%" alt="Get Started">
</p>

### Launch the software:

1. Click on the <a href="https://github.com/maxencebonamy/Fractal-Explorer/releases" target="_blank">Releases</a> button on the right and select the **latest version**.
2. Download the **.zip** archive and extract the files.
3. Open a terminal from the folder **Fractal-Explorer** and run one of the folowwing commands:
```
Fractal-Explorer.exe --fractal mandelbrot
```
```
Fractal-Explorer.exe --fractal burning-ship
```

### Compile:

> [!NOTE]
> *Prerequisites:*
> - [x] *Git must be installed on your computer. If not, <a href="https://git-scm.com/downloads" target="_blank">click here.</a>*
> - [x] *Xmake must be installed on your computer, if not, <a href="https://xmake.io/#/getting_started?id=installation" target="_blank">click here.</a>*
<br>

1. **Clone** the repository on your computer. To do this, open a terminal in the folder of your choice and run the following command:
```
git clone https://github.com/maxencebonamy/Fractal-Explorer
```

2. **Navigate** inside the folder you've just cloned with the following command:
```
cd Fractal-Explorer
```

3. **Compile** the project with the following command:
```
xmake
```

4. **Run** the executable with one of these commands:
```
xmake run main --fractal mandelbrot
```
```
xmake run main --fractal burning-ship
```

<br>

<p align="center">
	<img src="https://github.com/maxencebonamy/maxencebonamy/blob/main/assets/3_Features.png" width="100%" alt="Features">
</p>

### Actions you can perform in the software:
- Zoom in by scrolling mouse wheel upwards.
- Zoom out by scrolling mouse wheel downwards.
- Exit the software by pressing the ESC key.

### Parameters that can be passed on the command line:
- **--fractal** or **-f**: specify fractal name ("mandelbrot" or "burning-ship")
- **--fullscreen**: launch software in full screen mode
- **--cel-size** or **-c**: specify cell size in pixels (default 1). This is used to reduce image quality and therefore loading time between images.

**Example:** the following command will launch the software in full screen mode, and display the fractal burning ship with a resolution of 5 pixels per cell.
```
Fractal-Explorer.exe -f burning-ship -c 5 --fullscreen
```
![Capture d'écran 2023-09-28 124019](https://github.com/maxencebonamy/Fractal-Explorer/assets/66129931/7771e82c-3025-428b-a188-deda0789f698)
