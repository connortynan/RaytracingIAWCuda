from PIL import Image
import sys
import os


def ppmtopng(filepath: str) -> None:
    if os.path.isfile(filepath+".ppm"):
        with Image.open(filepath+".ppm") as im:
            im.convert("RGB").save(filepath+".png")
    else:
        print(f"file {filepath}.ppm not found!")


def main(args):
    if len(args) < 2:
        print("Must pass a filename! Usage: ppmtopng.py FILEPATH")
        return
    filename: str = args[1].split(".")[0]
    if os.path.isfile(filename+".ppm"):
        ppmtopng(filename)
        print(f"Successfully converted {filename}.ppm to {filename}.png")
    else:
        print(f"file {filename}.ppm not found!")


if __name__ == "__main__":
    main(sys.argv)