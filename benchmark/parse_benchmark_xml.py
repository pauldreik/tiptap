#!/usr/bin/env python3

# this converts the catch2 benchmark xml to something that is importable
# with libreoffice

import xml.etree.ElementTree as ET
tree = ET.parse('extensiveresults.xml')
root = tree.getroot()

firstrow = True

fileout = open('output.csv', mode='w', encoding="utf-8")

for child in root:
    print(child.tag, child.attrib)
    if child.tag == "TestCase":
        testcasename = child.get('name')
        N = testcasename[2:]
        output = {}
        print(f"testcase={testcasename}----N={N}-----------------------")
        for e in child:
            impl = e.get('name')
            print(f"child={impl}+++++++")
            print(e.tag, e.attrib)
            for details in e:
                if details.tag == "mean":
                    mean = details.get('value')
                    print(
                        f"found mean! testcase={testcasename} impl={impl} mean={mean}")
                    output[impl.replace('<' + N, "<N")] = float(mean) * 1e-6
                print(details.tag, details.attrib)
        print("complete case:===============================")
        print(output)
        if firstrow:
            print(
                'N;' + ';'.join([key for key in sorted(output.keys())]), file=fileout)
            firstrow = False
        print(N + ';' + ';'.join([str(output[key])
              for key in sorted(output.keys())]), file=fileout)

fileout.close()
