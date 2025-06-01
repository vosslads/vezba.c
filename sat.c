#include <stdio.h>
#include <stdlib.h> // Za abs() funkciju

// Vraća ugao kazaljke za sate (0-359 stepeni)
int hour_angle(int hours, int minutes) {
    hours = hours % 12; // Normalizujemo na 12-časovni format
    return (hours * 30) + (minutes / 2); // 30° po satu + 0.5° po minuti
}

// Vraća ugao kazaljke za minute (0-359 stepeni)
int min_angle(int minutes) {
    return (minutes % 60) * 6; // 6° po minuti
}

// Vraća manji (unutrašnji) ugao između kazaljki (0-180 stepeni)
int inner_angle_between_hands(int hours, int minutes) {
    int h_angle = hour_angle(hours, minutes);
    int m_angle = min_angle(minutes);
    int diff = abs(h_angle - m_angle);
    
    // Ako je ugao veći od 180°, vraćamo suplementni ugao
    return diff > 180 ? 360 - diff : diff;
}

int main() {
    int h = 1;
    int m = 30;
    
    printf("Unutrašnji ugao između kazaljki: %d°\n", inner_angle_between_hands(h, m));
    // Ispis: Unutrašnji ugao između kazaljki: 135°
    
    return 0;
}