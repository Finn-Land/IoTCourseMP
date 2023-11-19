// Begin: output
#define IOTEMPOWER_COMMAND_OUTPUT
#include <dev_output.h>
#define output_(internal_name, ...) \
    IOTEMPOWER_DEVICE_(Output, internal_name, ##__VA_ARGS__)
#define output(name, ...) IOTEMPOWER_DEVICE(name, output_, ##__VA_ARGS__)
#define out_(gcc_va_args...) output_(gcc_va_args)
#define out(gcc_va_args...) output(gcc_va_args)
#define led_(gcc_va_args...) output_(gcc_va_args)
#define led(gcc_va_args...) output(gcc_va_args)
#define relais_(gcc_va_args...) output_(gcc_va_args)
#define relais(gcc_va_args...) output(gcc_va_args)
// End: output

// Begin: input
#define IOTEMPOWER_COMMAND_INPUT
#include <dev_input.h>
#define input_(internal_name, ...) \
    IOTEMPOWER_DEVICE_(Input, internal_name, ##__VA_ARGS__)
#define input(name, ...) IOTEMPOWER_DEVICE(name, input_, ##__VA_ARGS__)
#define button_(gcc_va_args...) input_(gcc_va_args)
#define button(gcc_va_args...) input(gcc_va_args)
#define contact_(gcc_va_args...) input_(gcc_va_args)
#define contact(gcc_va_args...) input(gcc_va_args)
// End: input

// Begin: display
#define IOTEMPOWER_COMMAND_DISPLAY
#include <dev_display.h>
#define display_(internal_name, ...) \
    IOTEMPOWER_DEVICE_(Display, internal_name, ##__VA_ARGS__)
#define display(name, ...) IOTEMPOWER_DEVICE(name, display_, ##__VA_ARGS__)
// End: display

// Begin: display44780
#define IOTEMPOWER_COMMAND_DISPLAY44780
#include <dev_display.h>
#define display44780_(internal_name, ...) \
    IOTEMPOWER_DEVICE_(Display_HD44780_I2C, internal_name, ##__VA_ARGS__)
#define display44780(name, ...) IOTEMPOWER_DEVICE(name, display44780_, ##__VA_ARGS__)
// End: display44780

// Begin: mfrc522
#define IOTEMPOWER_COMMAND_MFRC522
#include <dev_mfrc522.h>
#define mfrc522_(internal_name, ...) \
    IOTEMPOWER_DEVICE_(Mfrc522, internal_name, ##__VA_ARGS__)
#define mfrc522(name, ...) IOTEMPOWER_DEVICE(name, mfrc522_, ##__VA_ARGS__)
#define rfid_(gcc_va_args...) mfrc522_(gcc_va_args)
#define rfid(gcc_va_args...) mfrc522(gcc_va_args)
// End: mfrc522

