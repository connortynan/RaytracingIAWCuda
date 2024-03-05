from PIL import Image
import sys
import os


def ppmtopng(filepath: str) -> None:
    with Image.open(filepath+".ppm") as im:
        im.convert("RGB").save(filepath+".png")


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