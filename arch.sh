sudo pacman -Syu
sudo pacman -S mesa vulkan-intel intel-media-driver
sudo pacman -S nvidia-open nvidia-utils egl-wayland
sed -i 's/MODULES=()/MODULES=(i915 nvidia nvidia_modeset nvidia_uvm nvidia_drm)' /etc/mkinitcpio.conf
sudo mkinitcpio -P
cat /sys/module/nvidia_drm/parameters/modeset
sudo pacman -S hyprland
sudo pacman -S \
kitty \
waybar \
wofi \
dunst \
dolphin \
hyprpaper \
hyprlock \
hypridle \
hyprcursor \
hyprpolkitagent \
xdg-desktop-portal \
xdg-desktop-portal-hyprland \
xdg-desktop-portal-gtk \
xorg-xwayland \
qt5-wayland \
qt6-wayland \
noto-fonts \
noto-fonts-emoji \
wl-clipboard \
grim \
slurp \
brightnessctl \
playerctl \
pavucontrol \
network-manager-applet \
bluez \
bluez-utils \
blueman
sudo systemctl enable --now bluetooth
sudo systemctl enable --now NetworkManager
clear
echo "########"
systemctl status NetworkManager
systemctl --user status wireplumber
systemctl status bluetooth