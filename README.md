<img width="1220" height="677" alt="Без названия247_20261005113508" src="https://github.com/user-attachments/assets/d4a60f81-9a78-4d10-873d-0384aa64311a" />



# Fork Hatsune Miku Desktop Mascot for hyprland / Форк Настольный маскот Хацунэ Мику на хупрленд


> That same Miku from the "slysh ty zalip, opa opa op" trend!
> 
> *Та самая Мику из тренда «слышь ты залип, опа опа оп»!*
> 
> [Переход на Русскую версию](README_RU.md)

---

## English Version


Desktop mascot for Linux written in pure C using the Raylib library. No Wallpaper Engine or Anima Engine required.


### Compatibility

* Fork 100% Working on: Hyprland


### Dependencies


* For Arch-based distros:
```bash

sudo pacman -S gcc make raylib libx11
```

* For Debian/Ubuntu-based distros:
```bash

sudo apt update
```
```bash

sudo apt install build-essential libraylib-dev libx11-dev libxext-dev
```

* For Fedora-based distros:
```bash
  sudo dnf install gcc make raylib-devel libX11-devel libXext-devel
  ```


### Building and Running

 * Clone the repository and enter the directory:
   
```bash
 git clone https://github.com/floppamqs1/miku-desktop-mascot-trend-hyprland.git
 ```
```bash
 cd miku-desktop-mascot-trend-hyprland
  ```

 * Also, you need add this on .config/hypr/config/windowrules.lua
```bash
  hl.window_rule({
    match = { title = "^(Hatsune Miku)$" },
    float = true,
    border_size = 0,
    no_shadow = true,
    no_blur = true,
    pin = true,
    no_initial_focus = true,
    opacity = "1.0 1.0 override",
    no_focus = true,
    move = { 1120, 433 },
  })
  ```

 * Compile
```bash
   gcc main.c -o miku -lraylib -lX11 -lGL -lm -lpthread -ldl -lrt -lXext
   ```
 * Run the mascot:
```bash
   ./miku
  ```


### Note

* Direct clicks on Miku are disabled. To close the mascot, run:
```bash
  pkill -9 -i miku
  ```