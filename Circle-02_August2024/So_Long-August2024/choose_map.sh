#!/bin/bash

# Directory containing the maps
MAP_DIR="maps"

printf "\n\e[1;92mWelcome to Operation Capybara freedom (So_Long)!\e[0m\n\n"

# List available maps
echo "Available maps:"
mapfile -t maps < <(ls "$MAP_DIR"/*.ber)
for i in "${!maps[@]}"; do
  echo "$i) ${maps[$i]}"
done

# Prompt the user to select a map
# shellcheck disable=SC2162
read -p "Select a map to play (enter the number): " map_index

# Check if the input is a valid number and within range
if [[ ! $map_index =~ ^[0-9]+$ ]] || [ "$map_index" -ge ${#maps[@]} ]; then
  echo "Invalid selection."
  exit 1
fi

# Run the game with the selected map
./so_long "${maps[$map_index]}"