<img width="1220" height="677" alt="Без названия247_20261005113508" src="https://github.com/user-attachments/assets/f830497f-a618-4114-a20b-4a9deaeb7d68" />



# Fork Hatsune Miku Desktop Mascot for hyprland / Форк Настольный маскот Хацунэ Мику на хупрленд


> *Та самая Мику из тренда «слышь ты залип, опа опа оп»!*
> > That same Miku from the "slysh ty zalip, opa opa op" trend!
> 
> [Read in English](README.md)
> ---
## Русская версия

Маскот для рабочего стола Linux, написанный на чистом C с использованием библиотеки Raylib. Никакого Wallpaper Engine или Anima Engine не требуется.

### Совместимость

 * Форк 100% работает на: Hyprland
 
### Зависимости

* Для Arch-подобных дистрибутивов:
```bash
sudo pacman -S gcc raylib libx11
```

* Для Debian/Ubuntu-подобных дистрибутивов:
```bash
sudo apt update
```
```bash
sudo apt install build-essential libraylib-dev libx11-dev libxext-dev

```
### Сборка и запуск

  * Клонируйте репозиторий и перейдите в папку:
```bash
  git clone https://github.com/floppamqs1/miku-desktop-mascot-trend-hyprland.git
   ```
```bash
   cd miku-desktop-mascot-trend-hyprland
   ```
  * Скомпилируйте:
```bash
   gcc main.c -o miku -lraylib -lX11 -lXext -lGL -lm -lpthread -ldl -lrt -lXext
   ```
  * Так же, пропишите в .config/hypr/config/windowrules.lua следующее:
```bash
  hl.window_rule({
    match = { title = "^(Hatsune Miku)$" },
    float = true,
    border_size = 0,
    no_shadow = true,
    no_blur = true,
    pin = true, -- Показывать на всех рабочих столах
    opacity = 1,
    no_initial_focus = true,
    opacity = "1.0 1.0 override",
    no_focus = true,
})
```

  * Запустите маскота:
```bash
   ./miku
   ```


### Примечание

 * На Мику не работают клики. Чтобы её закрыть, выполните в терминале:
```bash
  pkill -9 -i miku
  ```
