import sys
if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Need asm path")
        exit(1)
    path = sys.argv[1]
    # open files
    template = open(path + "/../template.cpp.template", "r")
    destination = open(path + "/../template.cpp", "w+")
    # handle ops
    dec = "\"" + open(path + "dec.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"") + "\""
    inc = "\"" + open(path + "inc.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"") + "\""
    left = "\"" + open(path + "left.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"") + "\""
    right = "\"" + open(path + "right.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"") + "\""
    in_ = "\"" + open(path + "in.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"") + "\""
    loopBegin = "\"" + open(path + "loopBegin.asm").read() \
        .replace("\n", "\\n").replace("loopBegin()", "\" + labelBegin + \"") \
        .replace("loopEnd()", "\" + labelEnd + \"") \
        .replace("label()", "\" + label + \"") + "\""
    loopEnd = "\"" + open(path + "loopEnd.asm").read() \
        .replace("\n", "\\n").replace("loopBegin()", "\" + labelBegin + \"") \
        .replace("loopEnd()", "\" + labelEnd + \"") + "\""
    begin = "\"" + open(path + "pre.asm").read() \
        .replace("\n", "\\n").replace("\"", "\\\"") + "\""
    end = "\"" + open(path + "end.asm").read() \
        .replace("\n", "\\n").replace("\"", "\\\"") + "\""
    out = "\"" + open(path + "out.asm").read() \
        .replace("\n", "\\n") + "\""
    add = "\"" + open(path + "add.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"")\
        .replace("value()", "\" + value + \"") + "\""
    subtract = "\"" + open(path + "subtract.asm").read() \
        .replace("\n", "\\n").replace("label()", "\" + label + \"")\
        .replace("value()", "\" + value + \"") \
        .replace("label2()", "\" + label2 + \"") + "\""

    temp = template.read().replace("$dec", dec) \
        .replace("$inc", inc) \
        .replace("$left", left) \
        .replace("$right", right) \
        .replace("$in", in_) \
        .replace("$loopBegin", loopBegin) \
        .replace("$loopEnd", loopEnd) \
        .replace("$begin", begin) \
        .replace("$end", end) \
        .replace("$out", out) \
        .replace("$add", add) \
        .replace("$subtract", subtract)
    destination.write(temp)
    destination.close()
