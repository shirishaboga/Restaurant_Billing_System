#include <stdio.h>
#include <string.h>
// Structure to store food item details
struct FoodItem {
    char name[100];
    float price;
    int quantity;
};
struct FoodItem cart[100]; // Shopping cart array to store ordered items
int cartSize = 0; // Number of items in the cart

// Function declarations for different menus
float vegetarianMenu();
float nonVegetarianMenu();
float thali();
float regionalFoods();
float beverages();
float desert(); 
void displayCart(float total); // Function to display final cart and bill

// Function to display the main menu
void displayMenu() {
    printf("\n--------------- MAIN MENU ---------------\n");
    printf("1. Vegetarian Menu\n");
    printf("2. Non-Vegetarian Menu\n");
    printf("3. Thali\n");
    printf("4. Regional Foods\n");
    printf("5. Beverages\n");
    printf("6. Deserts\n");
    printf("7. Exit and Show Bill\n");
}

int main() {
    int choice;
    float totalBill = 0;

    // Infinite loop to keep showing menu until user exits
    while (1) {
        displayMenu(); // Display the main menu options
        printf("\nEnter your choice: ");
        scanf("%d", &choice); // User's choice of menu

        // Menu Options using switch-case
        switch (choice) {
            case 1: totalBill += vegetarianMenu();
   break;
            case 2: totalBill += nonVegetarianMenu();
            break;
            case 3: totalBill += thali(); 
            break;
            case 4: totalBill += regionalFoods(); 
   break;
            case 5: totalBill += beverages(); 
   break;
            case 6: totalBill += desert(); 
   break; // Placeholder for desserts
            case 7:
                displayCart(totalBill); // Show final cart and total
                return 0; // Exit program
            default:
                printf("Invalid choice!\n"); // Handle wrong inputs
        }
    }
}

// Function to add food item to cart
void addToCart(const char *name, float price, int quantity) {
    // Check if item is already in the cart
    for (int i = 0; i < cartSize; i++) {
        if (strcmp(cart[i].name, name) == 0) {
            cart[i].quantity += quantity; // If found, increase quantity
            return;
        }
    }
    // If item not found, add new item to cart
    strcpy(cart[cartSize].name, name);
    cart[cartSize].price = price;
    cart[cartSize].quantity = quantity;
    cartSize++; // Increase cart size
}

//Function to display Vegetarian Menu and take orders
    float vegetarianMenu() {
    int choice, quantity;
    float total = 0;

    // Display vegetarian items
    printf("\n--- Vegetarian Menu ---\n");
    printf("1. Paneer Tikka - Rs150.00\n");
    printf("2. Veg Biryani - Rs300.00\n");
    printf("3. Aloo Paratha - Rs150.00\n");
    printf("4. Pav Bhaji - Rs50.00\n");
    printf("5. Palak Paneer - Rs200.00\n");
    printf("6. Kaju curry - Rs250.00\n");
    printf("7. Dal makhani - Rs250.00\n");
    printf("8. Tandoori aaloo - Rs200.50\n");
    printf("9. Chole bhature - Rs250.00\n");
    printf("10. Tandoori stuff Mushroom - Rs280.00\n");
    printf("11. Exit\n");

   
 
       while (1)  // Loop until user exits the vegetarian menu
{	
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 11)
        break;

        if(choice < 1 || choice > 11) {
        printf("Invalid choice!\n");
        continue;  
    }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Add item to cart and update total
        switch (choice) {
            case 1: addToCart("Paneer Tikka", 150.00, quantity); total += quantity * 150.00; break;
            case 2: addToCart("Veg Biryani", 300.00, quantity); total += quantity * 300.00; break;
            case 3: addToCart("Aloo Paratha", 150.00, quantity); total += quantity * 150.00; break;
            case 4: addToCart("Pav Bhaji", 50.00, quantity); total += quantity * 50.00; break;
            case 5: addToCart("Palak Paneer", 200.00, quantity); total += quantity * 200.00; break;
            case 6: addToCart("Kaju curry", 250.00, quantity); total += quantity * 250.00; break;
            case 7: addToCart("Dal makhni", 250.00, quantity); total += quantity * 250.00; break;
            case 8: addToCart("Tandoori aaloo", 200.50, quantity); total += quantity * 200.50; break;
            case 9: addToCart("Chole bhature", 250.00, quantity); total += quantity * 250.00; break;
            case 10: addToCart("Tandoori stuff Mushroom", 280.00, quantity); total += quantity * 280.00; break;
            default: printf("Invalid choice!\n"); // If user enters wrong number
        }
    }
    return total; // Return total cost of vegetarian items
}

// Function to display Non-Vegetarian Menu and take orders
    float nonVegetarianMenu() {
    int choice, quantity;
    float total = 0;

    // Displaying the Non-Vegetarian food items and their prices
    printf("\n--- Non-Vegetarian Menu ---\n");  
    printf("1. Chicken Biryani - Rs300.00\n");  
    printf("2. Mutton Korma - Rs250.00\n");  
    printf("3. Fish Fry - Rs350.00\n");  
    printf("4. Chicken Lollipop - Rs250.50\n");  
    printf("5. Mutton Biryani - Rs350.00\n");  
    printf("6. Fish Fingers - Rs250.00\n");  
    printf("7. Chicken 65 - Rs250.00\n");  
    printf("8. Prawn Masala - Rs300.00\n");  
    printf("9. Reshmi Kabab - Rs280.00\n");  
    printf("10. Seekh Kabab - Rs300.00\n");  
    printf("11. Exit\n");  // Option to exit this menu

    while (1) {  // Loop until user chooses to exit
    printf("Enter choice: ");  
        scanf("%d", &choice);  
        if (choice == 11)  // Exit the menu if user enters 11
            break; 

        if(choice < 1 || choice > 11) {
        printf("Invalid choice!\n");
        continue;  
    }
        printf("Enter quantity: ");  
        scanf("%d", &quantity);  

        // Add selected item to cart based on user's choice
        switch (choice) {  
            case 1: addToCart("Chicken Biryani", 300.00, quantity); 
                    total += quantity * 300.00;  
                    break;  
            case 2: addToCart("Mutton Curry", 250.00, quantity); 
                    total += quantity * 250.00;  
                    break;  
            case 3: addToCart("Fish Fry", 350.00, quantity); 
                    total += quantity * 350.00;  
                    break;  
            case 4: addToCart("Chicken Lollipop", 250.50, quantity); 
                    total += quantity * 250.50;  
                    break;  
            case 5: addToCart("Mutton Biryani", 350.00, quantity); 
                    total += quantity * 350.00;  
                    break;  
            case 6: addToCart("Fish Fingers", 250.00, quantity); 
                    total += quantity * 250.00;  
                    break;  
            case 7: addToCart("Chicken 65", 250.00, quantity); 
                    total += quantity * 250.00;  
                    break;  
            case 8: addToCart("Prawn Masala", 300.00, quantity); 
                    total += quantity * 300.00;  
                    break;  
            case 9: addToCart("Reshmi Kabab", 280.00, quantity); 
                    total += quantity * 280.00;  
                    break;  
            case 10: addToCart("Seekh Kabab", 300.00, quantity); 
                     total += quantity * 300.00;  
                     break;  
            default: 
                printf("Invalid choice!\n");  // If user enters wrong number
        }  
    }  
    return total;  // Return the total cost of ordered items
}
// Function to display Thali menu and take orders
float thali() {
    int choice, quantity;
    float total = 0;

    // Displaying the Thali Menu with food combinations and prices
    printf("\n--- Thali Menu ---\n");  
    printf("1. Tamilnadu Thali (Sambar, Rasam, Kootu, Poriyal, Curd Rice, Appalam, Payasam) - Rs350.00\n\n");  
    printf("2. Andhra Thali (Pappu, Pulihora, Gongura Pachadi, Gutti Vankaya, Curd, Avakaya, Payasam) - Rs450.00\n\n");  
    printf("3. Punjabi Thali (Dal Makhani, Paneer Butter Masala, Aloo Paratha, Chole, Jeera Rice, Lassi, Gulab Jamun) - Rs400.00\n\n");  
    printf("4. Rajasthani Thali (Dal Baati Churma, Gatte ki Sabzi, Ker Sangri, Bajra Roti, Chass, Ghevar) - Rs380.00\n\n");  
    printf("5. Bengali Thali (Shorshi Ilish, Chingri Malai Curry, Aloo Posto, Luchi, Mishti Doi, Rosogulla) - Rs400.00\n\n");  
    printf("6. Exit\n\n");  // Option to leave the Thali section

    while (1) {  // Infinite loop for ordering until user chooses to exit
        printf("Enter choice: ");  
        scanf("%d", &choice);  
        if (choice == 6)  // Exit the loop when user selects Exit
            break;  


        if(choice < 1 || choice > 6) {
        printf("Invalid choice!\n");
        continue;  
    }
        printf("Enter quantity: ");  
        scanf("%d", &quantity);  

        // Add selected thali to the cart and update the total
        switch (choice) {
            case 1: 
                addToCart("Tamilnadu Thali (Sambar, Rasam, Kootu, Poriyal, Curd Rice, Appalam, Payasam)", 350.00, quantity);  
                total += quantity * 350.00;  
                break;  
            case 2: 
                addToCart("Andhra Thali (Pappu, Pulihora, Gongura Pachadi, Gutti Vankaya, Curd, Avakaya, Payasam)", 450.00, quantity);  
                total += quantity * 450.00;  
                break;  
            case 3: 
                addToCart("Punjabi Thali (Dal Makhani, Paneer Butter Masala, Aloo Paratha, Chole, Jeera Rice, Lassi, Gulab Jamun)", 400.00, quantity);  
                total += quantity * 400.00;  
                break;  
            case 4: 
                addToCart("Rajasthani Thali (Dal Baati Churma, Gatte ki Sabzi, Ker Sangri, Bajra Roti, Chass, Ghevar)", 380.00, quantity);  
                total += quantity * 380.00;  
                break;  
            case 5: 
                addToCart("Bengali Thali (Shorshi Ilish, Chingri Malai Curry, Aloo Posto, Luchi, Mishti Doi, Rosogulla)", 400.00, quantity);  
                total += quantity * 400.00;  
                break;  
            default: 
                printf("Invalid choice!\n");  // If user enters wrong number
        }
    }
    return total;  // Return total cost for Thali orders
}
// Function to display Regional Foods menu and handle user's order
float regionalFoods() {
    int choice, quantity;
    float total = 0;
 
   // Displaying list of regional food items with prices
    printf("\n--- Regional Foods ---\n");  
    printf("1. South Indian Dosa - Rs100.00\n");  
    printf("2. Bengali Luchi - Rs120.00\n");  
    printf("3. Kerala Puttu - Rs150.00\n");  
    printf("4. Tamilnadu Pongal - Rs130.00\n");  
    printf("5. Maharashtrian Puran Poli - Rs150.00\n");  
    printf("6. Gujarati Dhokla - Rs70.00\n");  
    printf("7. Punjabi Dal Chawal - Rs150.00\n");  
    printf("8. Chettinad Curry - Rs100.00\n");  
    printf("9. Karnataka Ragi Mudde - Rs100.00\n");  
    printf("10. Andhra Pulihora - Rs100.00\n");  
    printf("11. Exit\n");  // Option to leave the regional menu

    while (1) {  // Keeps running until user chooses to exit
        printf("Enter choice: ");  
        scanf("%d", &choice);  
   if (choice == 11)  // Exit loop if user selects 11
            break;  

            if(choice < 1 || choice > 11) {
        printf("Invalid choice!\n");
        continue;  
    }

        printf("Enter quantity: ");  
        scanf("%d", &quantity);  

        //Add selected regional food to the cart and update the total
        switch (choice) {  
            case 1: 
                addToCart("South Indian Dosa", 100.00, quantity);  
                total += quantity * 100.00;   
                break;  
            case 2: 
                addToCart("Bengali Luchi", 120.00, quantity);  
                total += quantity * 120.00;   
                break;  
            case 3: 
                addToCart("Kerala Puttu", 150.00, quantity);  
                total += quantity * 150.00;   
                break;  
            case 4: 
                addToCart("Tamilnadu Pongal", 130.00, quantity);  
                total += quantity * 130.00;   
                break;  
            case 5: 
                addToCart("Maharashtrian Puran Poli", 150.00, quantity);  
                total += quantity * 150.00;   
                break;  
            case 6: 
                addToCart("Gujarati Dhokla", 70.00, quantity);  
                total += quantity * 70.00;   
                break;  
            case 7: 
                addToCart("Punjabi Dal Chawal", 150.00, quantity);  
                total += quantity * 150.00;   
                break;  
            case 8: 
                addToCart("Chettinad Curry", 100.00, quantity);  
                total += quantity * 100.00;   
                break;  
            case 9: 
                addToCart("Karnataka Ragi Mudde", 100.00, quantity);  
                total += quantity * 100.00;   
                break; 
case 10: 
                addToCart("Andhra Pulihora", 100.00, quantity);  
                total += quantity * 100.00;   
                break;  
            default: 
                printf("Invalid choice!\n");  // Handles invalid input
        }  
    }  
    return total;  // Returns total amount for regional food orders
}

// Function for Beverages Menu
float beverages() {
    int categoryChoice, itemChoice, quantity;
    float total = 0;

    while (1) {  
        // Display main beverages category menu
        printf("\n--- Beverages Menu ---\n");  
        printf("1. Juices\n");  
        printf("2. Mocktails\n");  
        printf("3. Coffee & Tea \n");  
       printf("4. Exit\n");  

        // Take user's category choice
        printf("Enter your choice: ");  
        scanf("%d", &categoryChoice);  
        if (categoryChoice == 4)  // Exit the beverages menu
            break;  


        if(categoryChoice < 1 || categoryChoice > 4) {
        printf("Invalid choice!\n");
        continue;  
    }

        switch (categoryChoice) {
            // JUICES MENU
            case 1:  
                printf("\n--- Juices ---\n");  
                printf("1. Strawberry Juice - Rs30\n");  
                printf("2. Pineapple Juice - Rs40\n");  
                printf("3. Blackberry Juice - Rs30\n");  
                printf("4. Raspberry Juice - Rs40\n");  
                printf("5. Kiwi Juice - Rs50\n");  
                printf("6. Mango Juice - Rs40\n");  
                printf("7. Exit\n");  // Exit from juices sub-menu

                while (1) {
                    printf("Enter choice: ");  
                    scanf("%d", &itemChoice);  
                    if (itemChoice == 7)  // Exit juice loop
                        break;  

                    if(itemChoice < 1 || itemChoice > 4) {
        printf("Invalid choice!\n");
        continue;  
    }

                    printf("Enter quantity: ");  
                    scanf("%d", &quantity);  

                    // Handle juice item selection and add to cart
                    switch (itemChoice) {
                        case 1: addToCart("Strawberry Juice", 30, quantity); total += quantity * 30; break;  
                        case 2: addToCart("Pineapple Juice", 40, quantity); total += quantity * 40; break;  
                        case 3: addToCart("Blackberry Juice", 30, quantity); total += quantity * 30; break;  
                        case 4: addToCart("Raspberry Juice", 40, quantity); total += quantity * 40; break;  
                        case 5: addToCart("Kiwi Juice", 50, quantity); total += quantity * 50; break;  
                        case 6: addToCart("Mango Juice", 40, quantity); total += quantity * 40; break;  
                        default: printf("Invalid choice!\n");
                    }
                }
                break;

            // MOCKTAILS MENU
            case 2:
                printf("\n--- Mocktails ---\n");  
                printf("1. Watermelon Mojito - Rs30\n");  
                printf("2. Raspberry Mojito - Rs30\n");  
                printf("3. Blueberry Lemonade Mojito - Rs30\n");  
                printf("4. Strawberry Mojito - Rs30\n");  
                printf("5. Pineapple Coconut Mojito - Rs30\n");  
                printf("6. Exit\n");  // Exit mocktails sub-menu

                while (1) {
                    printf("Enter choice: ");  
                    scanf("%d", &itemChoice);  
                    if (itemChoice == 6)  // Exit mocktails loop
                        break;
  

                    if(itemChoice < 1 || itemChoice > 4) {
        printf("Invalid choice!\n");
        continue;  
    }
                    printf("Enter quantity: ");
                  scanf("%d", &quantity);  

                    // Handle mocktail item selection and add to cart
                    switch (itemChoice) {
                        case 1: addToCart("Watermelon Mojito", 30, quantity); total += quantity * 30; break;  
                        case 2: addToCart("Raspberry Mojito", 30, quantity); total += quantity * 30; break;  
                        case 3: addToCart("Blueberry Lemonade Mojito", 30, quantity); total += quantity * 30; break;  
                        case 4: addToCart("Strawberry Mojito", 30, quantity); total += quantity * 30; break;  
                        case 5: addToCart("Pineapple Coconut Mojito", 30, quantity); total += quantity * 30; break;  
                        default: printf("Invalid choice!\n");
                    }
                }
                break;

            // COFFEE & TEA MENU
            case 3:
                printf("\n--- Coffee & Tea ---\n");  
                printf("1. Tea (Regular) - Rs20\n");  
                printf("2. Lemon Tea - Rs20\n");  
                printf("3. Masala Tea - Rs30\n");  
                printf("4. Ginger Tea - Rs30\n");  
                printf("5. Green Tea - Rs30\n");  
                printf("6. Black Tea - Rs40\n");  
                printf("7. Espresso - Rs60\n");  
                printf("8. Latte - Rs60\n");  
                printf("9. Exit\n");  // Exit tea/coffee sub-menu

                while (1) {
                    printf("Enter choice: ");  
                    scanf("%d", &itemChoice);  
                    if (itemChoice == 9)  // Exit coffee/tea loop
                        break;

                          if(itemChoice < 1 || itemChoice > 4) {
        printf("Invalid choice!\n");
        continue;  
    }
    
   printf("Enter quantity: ");  
                    scanf("%d", &quantity);  

                    // Handle coffee/tea item selection and add to cart
                    switch (itemChoice) {
                        case 1: addToCart("Tea (Regular)", 20, quantity); total += quantity * 20; break;  
                        case 2: addToCart("Lemon Tea", 20, quantity); total += quantity * 20; break;  
                        case 3: addToCart("Masala Tea", 30, quantity); total += quantity * 30; break;  
                        case 4: addToCart("Ginger Tea", 30, quantity); total += quantity * 30; break;  
                        case 5: addToCart("Green Tea", 30, quantity); total += quantity * 30; break;  
                        case 6: addToCart("Black Tea", 40, quantity); total += quantity * 40; break;  
                        case 7: addToCart("Espresso", 60, quantity); total += quantity * 60; break;  
                        case 8: addToCart("Latte", 60, quantity); total += quantity * 60; break;  
                        default: printf("Invalid choice!\n");
                    }
                }
                break;
            default:
                printf("Invalid category choice!\n");
        }
    }
    return total;  // Return total price of all beverage orders
}
// Function to display Desserts menu
float desert() {
    int choice, quantity;
    float total = 0;  // To keep track of total dessert cost
    // Display the dessert menu
    printf("\n--- Delicious Deserts ---\n");  
    printf("1. Gulab Jamun - Rs70.00\n");  
    printf("2. Rasmalai - Rs100.00\n");  
    printf("3. Jilebi - Rs50.00\n");  
    printf("4. Basundi - Rs100.00\n");  
    printf("5. Rasgulla - Rs150.00\n");  
    printf("6. Rabri - Rs100.50\n");  
    printf("7. Matka Kulfi - Rs70.00\n");  
    printf("8. Kesar Kulfi - Rs70.50\n");  
    printf("9. Gajar Halwa - Rs100.00\n");  
    printf("10. Brownie Ice-Cream Cup - Rs120.00\n");
    printf("11. Exit\n");

    // Loop to take multiple orders until user exits
    while (1) {
        printf("Enter choice: ");  // Get item choice
        scanf("%d", &choice);
        if (choice == 11) break;  // Exit if user selects 11

        if(choice < 1 || choice > 11) {
        printf("Invalid choice!\n");
        continue;  
    }
        printf("Enter quantity: ");  // Get quantity of selected item
        scanf("%d", &quantity);

        // Add selected item to cart and update total
        switch (choice) { 
           case 1: addToCart("Gulab Jamun", 70.00, quantity); total += quantity * 70.00; break;
            case 2: addToCart("Rasmalai", 100.00, quantity); total += quantity * 100.00; break;
            case 3: addToCart("Jilebi", 50.00, quantity); total += quantity * 50.00; break;
            case 4: addToCart("Basundi", 100.00, quantity); total += quantity * 100.00; break;
            case 5: addToCart("Rasgulla", 150.00, quantity); total += quantity * 150.00; break;
            case 6: addToCart("Rabri", 100.50, quantity); total += quantity * 100.50; break;
            case 7: addToCart("Matka Kulfi", 70.00, quantity); total += quantity * 70.00; break;
            case 8: addToCart("Kesar Kulfi", 70.50, quantity); total += quantity * 70.50; break;
            case 9: addToCart("Gajar Halwa", 100.00, quantity); total += quantity * 100.00; break;
            case 10: addToCart("Brownie Ice-Cream Cup", 120.00, quantity); total += quantity * 120.00; break;
            default: printf("Invalid choice\n");  // Handle invalid input
        }
    }
    return total;  // Return the total amount for all dessert orders
}

// Function to display the final bill with all items in the cart
#include <time.h>

void displayCart(float total) 
{
    time_t t;
    time(&t);

    printf("\n\n");
    printf("==================================================\n");
    printf("               SMART RESTAURANT  \n");
    printf("==================================================\n");
    printf("Date & Time: %s", ctime(&t));
    printf("--------------------------------------------------\n");

    printf("%-5s %-25s %-8s %-10s\n", "No", "Item", "Qty", "Amount");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < cartSize; i++) {
        printf("%-5d %-25s %-8d Rs%-10.2f\n",
               i + 1,
               cart[i].name,
               cart[i].quantity,
               cart[i].price * cart[i].quantity);
    }

    printf("--------------------------------------------------\n");
    printf("%-30s Rs%.2f\n", "TOTAL:", total);

    printf("==================================================\n");
    printf("         Thank You for Dining with Us!  \n");
    printf("                 Visit Again  \n");
    printf("==================================================\n\n");
}