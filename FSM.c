#include <stdio.h>
#include <stdint.h>

// STATES
typedef enum
{
    IDLE,
    DRIVE,
} ROBOT_STATE;

// EVENTS
typedef enum
{
    INPUT_IDLE,
    INPUT_DRIVE,
} INPUT_VALUE;

// Initial STATE
volatile ROBOT_STATE RState = IDLE;

void IDLEHandler(INPUT_VALUE input)
{
    if (input == INPUT_IDLE)
    {
        RState = IDLE;
        printf("REMAINS: S0\n");
    }
    else if (input == INPUT_DRIVE)
    {

        RState = DRIVE;
        printf("TRANSITIONS: S1\n");
    }
}

void DRIVEHandler(INPUT_VALUE input)
{

    if (input == INPUT_IDLE)
    {
        RState = IDLE;
        printf("TRANSITIONS: S0\n");
    }
    else if (input == INPUT_DRIVE)
    {
        RState = DRIVE;
        printf("REMAINS: S1\n");
    }
}

void StateMachineHandler(INPUT_VALUE event)
{
    switch (RState)
    {
    case IDLE:
        printf("\n__IDLE STATE__\n");
        IDLEHandler(event);
        break;
    case DRIVE:
        printf("\n__DRIVE STATE__\n");
        DRIVEHandler(event);
        break;
    default:
        break;
    }
}

int main()
{

    uint8_t i = 0;
    INPUT_VALUE input = INPUT_DRIVE;

    // NORMALLY it would be an infinite while loop
    while (i < 64)
    {

        // Simulate different inputs
        if (i % 2)
        {
            input = INPUT_IDLE;
        }
        else
        {
            input = INPUT_DRIVE;
        }

        StateMachineHandler(input);

        i++;
    }

    return 0;
}