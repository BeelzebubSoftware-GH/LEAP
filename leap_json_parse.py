import json
import pathlib
import argparse
import sys

path = f"{pathlib.Path.home()}/.leapbuffer/metadata.json"

try:
    with open(path) as file:
        data = json.load(file)
except FileNotFoundError:
    print(f"Error: File {path} not found.", file=sys.stderr)
    exit(1)
except json.JSONDecodeError as e:
    print(f"Error decoding JSON: {e}", file=sys.stderr)
    exit(1)

parser = argparse.ArgumentParser()
parser.add_argument("arg1")
args = parser.parse_args()

if args.arg1 not in data:
    print(f"Error: Key '{args.arg1}' not found in metadata.json.", file=sys.stderr)
    exit(1)

print(data[args.arg1])
