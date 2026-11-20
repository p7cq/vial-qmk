# Corne Choc Pro

## Vendor firmware

Clone repository:

```bash
git clone --recurse-submodules https://github.com/Keebart/vial-qmk-keebart
```

Build Vial firmware:

```bash
cd vial-qmk-keebart
qmk compile -kb keebart/corne_choc_pro/standard -km vial
```

## Custom firmware

Built on upstream Vial.

```bash
git clone --recurse-submodules https://github.com/vial-kb/vial-qmk
cd vial-qmk
qmk compile -kb keebart/p7cq -km default
```

## Matrix layout

The `{row,col}` matrix positions for each physical key.

Left half (rows 0–3):

```
(0,0) (0,1) (0,2) (0,3) (0,4) (0,5)  (0,6)
(1,0) (1,1) (1,2) (1,3) (1,4) (1,5)  (1,6)
(2,0) (2,1) (2,2) (2,3) (2,4) (2,5)
                  (3,3) (3,4) (3,5)
```

Right half (rows 4–7):

```
(4,6)  (4,5) (4,4) (4,3) (4,2) (4,1) (4,0)
(5,6)  (5,5) (5,4) (5,3) (5,2) (5,1) (5,0)
       (6,5) (6,4) (6,3) (6,2) (6,1) (6,0)
       (7,5) (7,4) (7,3)
```

- **Row numbering**: The right half's rows are numbered after the left
  half's (right row = left row + 4); each half has local rows 0–3.
- **Column numbering**: The right half is mirrored. Column 0 is the outer
  pinky column on both halves, and column 5 is the inner index column.

## RGB indicators

- **Caps Lock**: While Caps Lock is active, the large thumb keys lights
  red (`#cc241d`), regardless of which key `KC_CAPS` is mapped to. The
  keys are set by `caps_lock_keys`.
- **Power on**: For 3 seconds after boot, the same thumb keys of each
  half light blue (`#458588`). The keys and duration are set by
  `power_on_keys` and `POWER_ON_INDICATOR_MS`.

With RGB on, the indicators are drawn on top of the active effect; with RGB
off, only the indicator keys are lit.

## Flashing

Each half has its own RP2040 and must be flashed separately with the same
UF2 file. Enter the bootloader on a half, then copy the UF2 file to the
USB drive that appears.

- **Bootmagic**: Hold Q on the left half or P on the right half while
  connecting the USB cable to that half. This also resets the EEPROM, so any
  layout changes made in Vial are lost; save the layout in Vial first.
- **BOOT and RESET buttons**: Hold **BOOT**, briefly press and release
  **RESET**, then release **BOOT**. Both buttons are accessible through
  two small holes on the underside of the keyboard.
- **Key code**: Use a key mapped to `QK_BOOT`.

