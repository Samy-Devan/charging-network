// MCU A (Robot)
if (need_charging()) {
    broadcast_discover_request();
    wait_for_responses();
    select_station();
    send_connect_request();
    if (receive_handshake()) {
        while (charging_not_done()) {
            send_realtime_data();
            receive_realtime_data();
            delay(50); // ms, <100 ms interval
        }
        send_disconnect();
    }
}

//MCU B (Station)
while (true) {
    if (receive_discover_request()) {
        if (available)
            send_discover_response();
    }
    if (receive_connect_request()) {
        send_handshake(100_bytes);
        while (session_active()) {
            receive_realtime_data();
            send_realtime_data();
        }
        mark_available();
    }
}
