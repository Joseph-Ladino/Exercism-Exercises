import java.util.Random;

class DnDCharacter {

    int str, dex, con, itl, wis, chr, hp;

    int ability() {
        Random rn = new Random();
        return rn.nextInt(16) + 3;
    }

    int modifier(int input) {
        if(input < 10) return (int)((input - 11) / 2);
        else return (int)((input - 10) / 2 );
    }

    int getStrength() {
        return str;
    }

    int getDexterity() {
        return dex;
    }

    int getConstitution() {
        return con;
    }

    int getIntelligence() {
        return itl;
    }

    int getWisdom() {
        return wis;
    }

    int getCharisma() {
        return chr;
    }

    int getHitpoints() {
        return hp;
    }

    DnDCharacter() {
        str = ability();
        dex = ability();
        con = ability();
        itl = ability();
        wis = ability();
        chr = ability();
        hp = modifier(con) + 10;
    }
}
