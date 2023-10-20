#include "main.h"

/**
 * find_format_flags - Deduces the active formatting instructions.
 * @fmt_seq: The sequence with potential flags.
 * @idx: Reference to the current position in the string.
 * Return: Computed flags.
 */
int find_format_flags(const char *fmt_seq, int *idx)
{
    int flag_idx, curr_loc;
    int determined_flags = 0;

    /* Flag representations and their corresponding values */
    const char FLAG_CHARS[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAG_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (curr_loc = *idx + 1; fmt_seq[curr_loc]; curr_loc++)
    {
        int found = 0;

        for (flag_idx = 0; FLAG_CHARS[flag_idx]; flag_idx++)
        {
            if (fmt_seq[curr_loc] == FLAG_CHARS[flag_idx])
            {
                determined_flags |= FLAG_VALUES[flag_idx];
                found = 1;
                break;
            }
        }

        if (!found)
            break;
    }

    *idx = curr_loc - 1;
    return (determined_flags);
}

