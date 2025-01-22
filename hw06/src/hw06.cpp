#include "hw06.h"
#include <iostream>

Hall create_hall(int hall_id, int rows, int seats_per_row) {
    Hall hall;
    hall.id = hall_id;
    hall.rows = rows;
    hall.seats_per_row = seats_per_row;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < seats_per_row; ++j) {
            hall.seats.push_back({i, j, false});
        }
    }
    return hall;
}

Session create_session(int session_id, const std::string& movie_title, Hall& hall) {
    return Session{session_id, movie_title, hall};
}

bool reserve_seat(Session& session, int row, int seat_number) {
    if (row < 0 || row >= session.hall.rows || seat_number < 0 || seat_number >= session.hall.seats_per_row) {
        std::cerr << "Invalid seat selection." << std::endl;
        return false;
    }
    for (auto& seat : session.hall.seats) {
        if (seat.row == row && seat.number == seat_number) {
            if (seat.is_reserved) {
                std::cerr << "Seat already reserved." << std::endl;
                return false;
            }
            seat.is_reserved = true;
            return true;
        }
    }
    std::cerr << "Seat not found." << std::endl;
    return false;
}

bool cancel_reservation(Session& session, int row, int seat_number) {
    if (row < 0 || row >= session.hall.rows || seat_number < 0 || seat_number >= session.hall.seats_per_row) {
        std::cerr << "Invalid seat selection." << std::endl;
        return false;
    }
    for (auto& seat : session.hall.seats) {
        if (seat.row == row && seat.number == seat_number) {
            if (!seat.is_reserved) {
                std::cerr << "Seat is not reserved." << std::endl;
                return false;
            }
            seat.is_reserved = false;
            return true;
        }
    }
    std::cerr << "Seat not found." << std::endl;
    return false;
}

void display_hall(const Hall& hall) {
    for (int i = 0; i < hall.rows; ++i) {
        for (int j = 0; j < hall.seats_per_row; ++j) {
            bool is_reserved = false;
            for (const auto& seat : hall.seats) {
                if (seat.row == i && seat.number == j) {
                    is_reserved = seat.is_reserved;
                    break;
                }
            }
            std::cout << (is_reserved ? "[X]" : "[ ]");
        }
        std::cout << std::endl;
    }
}

int get_available_seats(const Hall& hall) {
    int available_seats = 0;
    for (const auto& seat : hall.seats) {
        if (!seat.is_reserved) {
            ++available_seats;
        }
    }
    return available_seats;
}
