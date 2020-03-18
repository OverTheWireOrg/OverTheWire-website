#!/usr/bin/env python

import sys, json, csv, pprint

patrons = []

with open(sys.argv[1]) as csvfile:
    csvrows = csv.DictReader(csvfile)
    for row in csvrows:
        name = row["Name"]
        pledge = float(row["Pledge $"].replace("$",""))
        lifetime = float(row["Lifetime $"].replace("$",""))
        status = row["Patron Status"]
        details = row["Additional Details"]
        since = row["Patronage Since Date"]

        if details != "":
            name = details

        if status == "Active patron":
            if lifetime > 0 and pledge >= 5:
                patrons += [(name, lifetime, since)]

patreons = sorted(patrons, key=lambda x: x[2])

for (name, lifetime, since) in patreons:
    print "* {}".format(name)
