class cevirici:
    def giris(self):
        harfler=input()
        return harfler

    def harf(self,gelen):
        for karakterler in gelen:
            if(karakterler == "a"):
                print(".-")
            if (karakterler == "b"):
                print("-...")
            if (karakterler == "c"):
                print("-.-.")
            if (karakterler == "d"):
                print("-..")
            if (karakterler == "e"):
                print(".")
            if (karakterler == "f"):
                print("..-.")
            if (karakterler == "g"):
                print("--.")
            if (karakterler == "h"):
                print("....")
            if (karakterler == "i"):
                print("..")
            if (karakterler == "j"):
                print(".---")
            if (karakterler == "k"):
                print("-.-")
            if (karakterler == "l"):
                print(".-..")
            if (karakterler == "m"):
                print("--")
            if (karakterler == "n"):
                print("-.")
            if (karakterler == "o"):
                print("---")
            if (karakterler == "p"):
                print(".--.")
            if (karakterler == "r"):
                print(".-.")
            if (karakterler == "s"):
                print("...")
            if (karakterler == "t"):
                print("-")
            if (karakterler == "u"):
                print("..-")
            if (karakterler == "v"):
                print("...-")
            if (karakterler == "y"):
                print("-.--")
            if (karakterler == "z"):
                print("--..")
            if(karakterler == "/"):
                print("**************************************************************")


mors=cevirici()
while(1):
    kelime=mors.giris()
    mors.harf(kelime)