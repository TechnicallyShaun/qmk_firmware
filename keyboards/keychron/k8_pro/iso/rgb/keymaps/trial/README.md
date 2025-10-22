# K8 Pro ISO RGB - Trial Keymap

Custom keymap with Caps/Ctrl swap and Home Row Mods.

## Features

### 1. Caps Lock ↔ Ctrl Swap
- **Caps Lock position** → Acts as **Ctrl**
- **Left Ctrl position** → Acts as **Caps Lock**
- Applied to both Mac and Windows layers

### 2. Home Row Mods (GACS Order)
Home row keys act as modifiers when held:

**Left Hand:**
- `A` → Tap: a | Hold: GUI (Win/Cmd)
- `S` → Tap: s | Hold: Alt
- `D` → Tap: d | Hold: Ctrl
- `F` → Tap: f | Hold: Shift

**Right Hand:**
- `J` → Tap: j | Hold: Shift
- `K` → Tap: k | Hold: Ctrl
- `L` → Tap: l | Hold: Alt
- `;` → Tap: ; | Hold: GUI (Win/Cmd)

**Usage Examples:**
- Hold `D` + tap `C` = Ctrl+C (copy)
- Hold `D` + tap `V` = Ctrl+V (paste)
- Hold `S` + tap `Tab` = Alt+Tab (switch windows)

**Timing:**
- Tapping term: 200ms
- Quick tap: 100ms (allows fast double-taps)

## Building

```bash
qmk compile -kb keychron/k8_pro/iso/rgb -km trial
```

## Flashing

Use QMK Toolbox to flash `keychron_k8_pro_iso_rgb_trial.bin`
