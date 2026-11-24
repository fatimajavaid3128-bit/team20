#include "SupplyChain.h"
#include "raylib.h"
#include <iostream>
using namespace std;

int main() {

    // creating the four supply chain stages

    SupplyChain mining("Mining", "Extracting raw materials from the Earth.", 0);

    SupplyChain manufacturing("Manufacturing", "Turning manufactured materials\ninto smartphone components.", 0);

    SupplyChain transportation("Transportation", "Shipping smartphone components\nand finished products.", 0);

    SupplyChain stores("Stores", "Selling finished smartphones to consumers.", 0);

    // open raylib window
    InitWindow(1000, 600, "Smartphone Supply Chain");
    SetTargetFPS(60);

    // load images
    Texture2D miningImage = LoadTexture("images/mining.png");
    Texture2D manufacturingImage = LoadTexture("images/manufacturing.png");
    Texture2D transportationImage = LoadTexture("images/transportation.png");
    Texture2D storesImage = LoadTexture("images/stores.png");

    // 0 = Main Screen
    // 1 = Mining
    // 2 = Manufacturing
    // 3 = Transportation
    // 4 = Stores

    int screen = 0;
    int page = 1;

    // Main screen buttons
    Rectangle miningBox = {100, 200, 380, 140};
    Rectangle manufacturingBox = {520, 200, 380, 140};
    Rectangle transportationBox = {100, 380, 380, 140};
    Rectangle storesBox = {520, 380, 380, 140};

    // Back button
    Rectangle backButton = {50, 520, 150, 50};

    // Next button
    Rectangle nextButton = {800, 520, 150, 50};

    while (!WindowShouldClose()) {

        Vector2 mouse = GetMousePosition();

        // MAIN SCREEN
        if (screen == 0) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

                if (CheckCollisionPointRec(mouse, miningBox)) {
                    screen = 1;
                    page = 1;
                    mining.PrintInfo();
                }

                else if (CheckCollisionPointRec(mouse, manufacturingBox)) {
                    screen = 2;
                    page = 1;
                    manufacturing.PrintInfo();
                }

                else if (CheckCollisionPointRec(mouse, transportationBox)) {
                    screen = 3;
                    page = 1;
                    transportation.PrintInfo();
                }

                else if (CheckCollisionPointRec(mouse, storesBox)) {
                    screen = 4;
                    page = 1;
                    stores.PrintInfo();
                }
            }
        }

        // DETAIL SCREEN: Back and Next buttons
        else {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {

                if (CheckCollisionPointRec(mouse, backButton)) {
                    if (page == 2) {
                        page = 1;
                    }
                    else {
                        screen = 0;
                    }
                }

                else if (CheckCollisionPointRec(mouse, nextButton)) {
                    if (page == 1) {
                        page = 2;
                    }
                }
            }
        }

        BeginDrawing();

        ClearBackground(Color{21, 31, 48, 255});

        // MAIN SCREEN
        if (screen == 0) {

            DrawText("The Smartphone Supply Chain", 200, 50, 35, WHITE);

            // Mining hover effect
            if (CheckCollisionPointRec(mouse, miningBox)) {
                DrawRectangleRec(miningBox, DARKGREEN);
            }
            else {
                DrawRectangleRec(miningBox, Color{40, 75, 54, 255});
            }

            // Mining image
            Rectangle miningSource = {0, 0, (float)miningImage.width, (float)miningImage.height};
            Rectangle miningDest = {110, 210, 120, 120};

            DrawTexturePro(miningImage, miningSource, miningDest, {0, 0}, 0.0f, WHITE);

            DrawText("Mining", 285, 255, 30, WHITE);

            // Manufacturing hover effect
            if (CheckCollisionPointRec(mouse, manufacturingBox)) {
                DrawRectangleRec(manufacturingBox, DARKBLUE);
            }
            else {
                DrawRectangleRec(manufacturingBox, Color{38, 63, 96, 255});
            }

            // Manufacturing image
            Rectangle manufacturingSource = {0, 0, (float)manufacturingImage.width, (float)manufacturingImage.height};
            Rectangle manufacturingDest = {530, 210, 120, 120};

            DrawTexturePro(manufacturingImage, manufacturingSource, manufacturingDest, {0, 0}, 0.0f, WHITE);

            DrawText("Manufacturing", 665, 255, 26, WHITE);

            // Transportation hover effect
            if (CheckCollisionPointRec(mouse, transportationBox)) {
                DrawRectangleRec(transportationBox, ORANGE);
            }
            else {
                DrawRectangleRec(transportationBox, Color{101, 75, 45, 255});
            }

            // Transportation image
            Rectangle transportationSource = {0, 0, (float)transportationImage.width, (float)transportationImage.height};
            Rectangle transportationDest = {110, 390, 120, 120};

            DrawTexturePro(transportationImage, transportationSource, transportationDest, {0, 0}, 0.0f, WHITE);

            DrawText("Transportation", 245, 435, 26, WHITE);

            // Stores hover effect
            if (CheckCollisionPointRec(mouse, storesBox)) {
                DrawRectangleRec(storesBox, PURPLE);
            }
            else {
                DrawRectangleRec(storesBox, Color{78, 54, 95, 255});
            }

            // Stores image
            Rectangle storesSource = {0, 0, (float)storesImage.width, (float)storesImage.height};
            Rectangle storesDest = {530, 390, 120, 120};

            DrawTexturePro(storesImage, storesSource, storesDest, {0, 0}, 0.0f, WHITE);

            DrawText("Stores", 725, 435, 30, WHITE);

            DrawText("Click on a stage to explore it", 300, 550, 20, WHITE);
        }

        // MINING SCREEN
        else if (screen == 1) {

            if (page == 1) {

                DrawText("MINING", 400, 50, 40, Color{120, 200, 150, 255});
                DrawText(mining.GetDescription().c_str(), 100, 150, 22, WHITE);
                DrawText("Cost: $4.99 per unit", 100, 220, 22, WHITE);
                DrawText("Click NEXT to learn more", 100, 300, 20, LIGHTGRAY);

                // Mining image
                Rectangle source = {0, 0, (float)miningImage.width, (float)miningImage.height};
                Rectangle dest = {600, 130, 320, 300};

                DrawTexturePro(miningImage, source, dest, {0, 0}, 0.0f, WHITE);
            }

            else if (page == 2) {

                DrawText("MINING - RESEARCH", 300, 50, 35, Color{120, 200, 150, 255});

                // Raw materials section
                DrawRectangle(70, 110, 860, 110, Color{40, 75, 54, 255});

                DrawText("Raw Materials", 90, 125, 24, Color{120, 200, 150, 255});
                DrawText("Mining is the first stage of making a smartphone.", 90, 160, 20, WHITE);
                DrawText("Materials include lithium, cobalt, copper, gold, aluminum, silicon, and tin.", 90, 185, 20, WHITE);

                // Material uses section
                DrawRectangle(70, 235, 860, 155, Color{40, 75, 54, 255});

                DrawText("How These Materials Are Used", 90, 250, 24, Color{120, 200, 150, 255});
                DrawText("Lithium and cobalt - Batteries", 90, 285, 20, WHITE);
                DrawText("Copper - Electrical connections", 90, 310, 20, WHITE);
                DrawText("Gold - Electronic components", 90, 335, 20, WHITE);
                DrawText("Silicon - Processors", 90, 360, 20, WHITE);

                // Global impact section
                DrawRectangle(70, 405, 860, 100, Color{40, 75, 54, 255});

                DrawText("Global Impact", 90, 420, 24, Color{120, 200, 150, 255});
                DrawText("Mining uses natural resources and involves workers", 90, 455, 20, WHITE);
                DrawText("from different parts of the world.", 90, 480, 20, WHITE);
            }
        }

        // MANUFACTURING SCREEN
        else if (screen == 2) {

            if (page == 1) {

                DrawText("MANUFACTURING", 320, 50, 40, Color{130, 180, 240, 255});
                DrawText(manufacturing.GetDescription().c_str(), 100, 150, 22, WHITE);
                DrawText("Cost: $403.10 per unit", 100, 220, 22, WHITE);
                DrawText("Click NEXT to learn more", 100, 300, 20, LIGHTGRAY);

                // Manufacturing image
                Rectangle source = {0, 0, (float)manufacturingImage.width, (float)manufacturingImage.height};
                Rectangle dest = {600, 130, 320, 300};

                DrawTexturePro(manufacturingImage, source, dest, {0, 0}, 0.0f, WHITE);
            }

            else if (page == 2) {

                DrawText("MANUFACTURING - RESEARCH", 230, 50, 35, Color{130, 180, 240, 255});

                // Component production section
                DrawRectangle(70, 110, 860, 110, Color{38, 63, 96, 255});

                DrawText("Component Production", 90, 125, 24, Color{130, 180, 240, 255});
                DrawText("After mining, materials are sent to factories.", 90, 160, 20, WHITE);
                DrawText("They are processed into smartphone components.", 90, 185, 20, WHITE);

                // Assembly section
                DrawRectangle(70, 235, 860, 155, Color{38, 63, 96, 255});

                DrawText("Smartphone Assembly", 90, 250, 24, Color{130, 180, 240, 255});
                DrawText("Different companies manufacture different parts.", 90, 285, 20, WHITE);
                DrawText("These include batteries, screens, cameras,", 90, 310, 20, WHITE);
                DrawText("processors, and circuit boards.", 90, 335, 20, WHITE);
                DrawText("Workers and machines assemble the phone.", 90, 360, 20, WHITE);

                // Testing section
                DrawRectangle(70, 405, 860, 100, Color{38, 63, 96, 255});

                DrawText("Software and Testing", 90, 420, 24, Color{130, 180, 240, 255});
                DrawText("The operating system is installed.", 90, 455, 20, WHITE);
                DrawText("Phones are tested to make sure their features work properly.", 90, 480, 20, WHITE);
            }
        }

        // TRANSPORTATION SCREEN
        else if (screen == 3) {

            if (page == 1) {

                DrawText("TRANSPORTATION", 320, 50, 40, Color{255, 180, 90, 255});
                DrawText(transportation.GetDescription().c_str(), 100, 150, 22, WHITE);
                DrawText("Cost: $9.98 per unit", 100, 220, 22, WHITE);
                DrawText("Click NEXT to learn more", 100, 300, 20, LIGHTGRAY);

                // Transportation image
                Rectangle source = {0, 0, (float)transportationImage.width, (float)transportationImage.height};
                Rectangle dest = {600, 130, 320, 300};

                DrawTexturePro(transportationImage, source, dest, {0, 0}, 0.0f, WHITE);
            }

            else if (page == 2) {

                DrawText("TRANSPORTATION - RESEARCH", 230, 50, 35, Color{255, 180, 90, 255});

                // Packaging section
                DrawRectangle(70, 110, 860, 110, Color{101, 75, 45, 255});

                DrawText("Packaging", 90, 125, 24, Color{255, 180, 90, 255});
                DrawText("After assembly, smartphones are packaged in boxes.", 90, 160, 20, WHITE);
                DrawText("This protects them from damage during travel.", 90, 185, 20, WHITE);

                // Transportation methods section
                DrawRectangle(70, 235, 860, 155, Color{101, 75, 45, 255});

                DrawText("Methods of Transportation", 90, 250, 24, Color{255, 180, 90, 255});
                DrawText("Cargo ships", 90, 285, 20, WHITE);
                DrawText("Airplanes", 90, 310, 20, WHITE);
                DrawText("Trucks", 90, 335, 20, WHITE);
                DrawText("Phones may travel through different countries.", 90, 360, 20, WHITE);

                // Distribution section
                DrawRectangle(70, 405, 860, 100, Color{101, 75, 45, 255});

                DrawText("Distribution", 90, 420, 24, Color{255, 180, 90, 255});
                DrawText("Phones may stop at warehouses and distribution centers.", 90, 455, 20, WHITE);
                DrawText("Transportation connects factories, stores, and customers.", 90, 480, 20, WHITE);
            }
        }

        // STORES SCREEN
        else if (screen == 4) {

            if (page == 1) {

                DrawText("STORES", 400, 50, 40, Color{200, 155, 230, 255});
                DrawText(stores.GetDescription().c_str(), 100, 150, 22, WHITE);
                DrawText("Cost: $780.92 per unit", 100, 220, 22, WHITE);
                DrawText("Click NEXT to learn more", 100, 300, 20, LIGHTGRAY);

                // Stores image
                Rectangle source = {0, 0, (float)storesImage.width, (float)storesImage.height};
                Rectangle dest = {600, 130, 320, 300};

                DrawTexturePro(storesImage, source, dest, {0, 0}, 0.0f, WHITE);
            }

            else if (page == 2) {

                DrawText("STORES - RESEARCH", 320, 50, 35, Color{200, 155, 230, 255});

                // Retail section
                DrawRectangle(70, 110, 860, 110, Color{78, 54, 95, 255});

                DrawText("Retail Stores", 90, 125, 24, Color{200, 155, 230, 255});
                DrawText("Stores are the final stage of the supply chain.", 90, 160, 20, WHITE);
                DrawText("Phones are unpacked and placed on display.", 90, 185, 20, WHITE);

                // Customer experience section
                DrawRectangle(70, 235, 860, 155, Color{78, 54, 95, 255});

                DrawText("Customer Experience", 90, 250, 24, Color{200, 155, 230, 255});
                DrawText("Customers can compare different smartphone models.", 90, 285, 20, WHITE);
                DrawText("Employees help customers learn about features.", 90, 310, 20, WHITE);
                DrawText("Customers can compare prices.", 90, 335, 20, WHITE);
                DrawText("Phones can be purchased in stores or online.", 90, 360, 20, WHITE);

                // Final price section
                DrawRectangle(70, 405, 860, 100, Color{78, 54, 95, 255});

                DrawText("Final Price", 90, 420, 24, Color{200, 155, 230, 255});
                DrawText("The price can include manufacturing, transportation, packaging,", 90, 455, 20, WHITE);
                DrawText("advertising, taxes, and the store's profit.", 90, 480, 20, WHITE);
            }
        }

        // Buttons on all detail screens
        if (screen != 0) {

            // Back button hover effect
            if (CheckCollisionPointRec(mouse, backButton)) {
                DrawRectangleRec(backButton, RED);
            }
            else {
                DrawRectangleRec(backButton, DARKGRAY);
            }

            DrawText("BACK", 90, 535, 20, WHITE);

            // Next button only appears on page 1
            if (page == 1) {

                if (CheckCollisionPointRec(mouse, nextButton)) {
                    DrawRectangleRec(nextButton, DARKGREEN);
                }
                else {
                    DrawRectangleRec(nextButton, DARKGRAY);
                }

                DrawText("NEXT", 850, 535, 20, WHITE);
            }
        }

        EndDrawing();
    }

    // unload images
    UnloadTexture(miningImage);
    UnloadTexture(manufacturingImage);
    UnloadTexture(transportationImage);
    UnloadTexture(storesImage);

    // close raylib
    CloseWindow();

    return 0;
}
