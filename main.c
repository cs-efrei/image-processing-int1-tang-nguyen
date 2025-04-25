#include <stdio.h>
#include <stdlib.h>

#include "bmp8.h"
#include "t_bmp8.h"

void print_main_menu() {
    printf("\nPlease choose an option:\n");
    printf("1. Open an image\n");
    printf("2. Save an image\n");
    printf("3. Apply a filter\n");
    printf("4. Display image information\n");
    printf("5. Quit\n");
}

void print_filter_menu() {
    printf("\nPlease choose a filter:\n");
    printf("1. Negative\n");
    printf("2. Brightness\n");
    printf("3. Black and white (Threshold)\n");
    printf("4. Return to the previous menu\n");
}

int main(void)
{
    t_bmp8 *image = NULL;
    int choice;
    int running = 1;

    while (running) {
        print_main_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char filename[100];
                printf("Enter image filename (example: barbara_gray.bmp): ");
                scanf("%s", filename);
                image = bmp8_loadImage(filename);
                if (image != NULL) {
                    printf("Image loaded successfully!\n");
                } else {
                    printf("Failed to load image.\n");
                }
                break;
            }

            case 2: {
                if (image == NULL) {
                    printf("No image loaded!\n");
                    break;
                }
                char save_name[100];
                printf("Enter filename to save (example: result.bmp): ");
                scanf("%s", save_name);
                bmp8_saveImage2(save_name, image);
                printf("Image saved successfully!\n");
                break;
            }

            case 3: {
                if (image == NULL) {
                    printf("No image loaded!\n");
                    break;
                }

                int filter_choice;
                print_filter_menu();
                scanf("%d", &filter_choice);

                switch (filter_choice) {
                    case 1:
                        bmp8_negative(image);
                        printf("Negative filter applied.\n");
                        break;

                    case 2: {
                        int value;
                        printf("Enter brightness value (-255 to 255): ");
                        scanf("%d", &value);
                        bmp8_brightness(image, value);
                        printf("Brightness adjusted.\n");
                        break;
                    }

                    case 3: {
                        int threshold;
                        printf("Enter threshold value (0 to 255): ");
                        scanf("%d", &threshold);
                        bmp8_threshold(image, threshold);
                        printf("Threshold filter applied.\n");
                        break;
                    }

                    case 4:
                        break;

                    default:
                        printf("Invalid filter choice.\n");
                        break;
                }
                break;
            }

            case 4:
                if (image != NULL) {
                    bmp8_printInfo(image);
                } else {
                    printf("No image loaded!\n");
                }
                break;

            case 5:
                running = 0;
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    if (image != NULL) {
        bmp8_free(image);
    }

    printf("Goodbye!\n");
    return 0;
}