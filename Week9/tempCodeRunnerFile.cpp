void fillRegion(int x0, int y0, int x1, int y1) {
    if (!screen) return;

    static char letter = 'A';

    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            screen[i][j] = letter;          // Overwrite past regions and icons
        }
    }

    // Use the next letter of the alphabet
    letter = letter + 1;
}