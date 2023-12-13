#!/usr/bin/python3
"""Simple Status Code logger written in python"""
import re  # pattern finding
import collections  # faster dictionary creation
import operator  # for faster item retrival from dict


def parse_input(line) -> tuple:
    """Parses the inputs and return the status codes
    file size
    Args:
        line (str): data from the standard input
    Return:
        returns the file size and the status code inside
        the line data from stdinput
    """
    pattern = re.compile(
            r'(\S+)\s*-\s*\[(.*?)\] "GET /projects/260 HTTP/1.1" (\S+) (\d+)'
    )
    match = pattern.match(line)

    if match:
        ip_address, date, status_code, file_size = match.groups()
        return file_size, status_code
    else:
        return None


def printer(total_size, status_codes_counter) -> None:
    """prints the required format to stdout
    Args:
        total_size (int): total value of all the first ten status code
        status_codes_counter (dict): key value pairs of the status code
        and their respective number of appearance
    """
    status_totals = sorted(status_codes_counter.items(),
                           key=operator.itemgetter(0))
    print("File size: {}".format(total_size))
    for code, count in status_totals:
        print("{}: {}".format(code, count))


# Entry point
if __name__ == "__main__":
    status_codes_counter = collections.Counter()
    total_size = 0
    n = -1
    try:
        while (line := input()):
            try:
                try:
                    tuple_res = parse_input(line)
                    total_size += int(tuple_res[0])
                    status_codes_counter.update([int(tuple_res[1])])
                    n += 1
                except (ValueError, TypeError):
                    continue
                if (n + 1) % 10 == 0:
                    printer(total_size, status_codes_counter)
            except KeyboardInterrupt:
                printer(total_size, status_codes_counter)
        if (n) % 10 != 0:
            printer(total_size, status_codes_counter)
    except (EOFError, KeyboardInterrupt):
        printer(total_size, status_codes_counter)
