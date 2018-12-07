/*
File: Interface.java

Description: Interface.java defines a collection of useful static methods for reading
             and evaluating user input.

Author: Alexander DuPree

Assignment: Program 5

Date: 24 November 2018
 */

package com.user_interface;

import java.io.IOException;
import java.util.Scanner;

public class Interface {

    private static final Scanner input = new Scanner(System.in);

    public static void pause_console() {
        pause_console("\nPress ENTER to continue");
    }

    public static void pause_console(String prompt) {
        System.out.println(prompt);
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static String get_input() {
        return get_input("> ");
    }

    public static String get_input(String prompt) {
        System.out.print(prompt);
        return input.next();
    }

    public static int get_int(String prompt, int min, int max) {

        // TODO, handle underflow for small min
        int data = min - 1;

        while (data < min || data > max) {
            System.out.print(prompt);

            try {
                data = input.nextInt();
            } catch (java.util.InputMismatchException err) {
                data = min;
                System.out.println("Sorry, I don't understand. Defaulting to first selection.");
            }

            if (data < min || data > max) {
                System.out.println("\nPlease enter a number between " + min + " - " + max + " inclusive");
            }
        }
        return data;
    }

    public static boolean again() {
        return again("Again? Y/N: ", "y");
    }

    public static boolean again(String prompt, String yes_pattern) {
        System.out.println(prompt);
        return input.next().contains(yes_pattern);
    }
}
