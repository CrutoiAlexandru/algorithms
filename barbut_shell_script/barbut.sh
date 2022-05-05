#! /bin/bash

balance=100

printf "Bun venit la barbut!\n\n"

coin=("btc" "eth" "usd" "eur" "ron")

printf "Alege moneda!\n\n"

for i in "${!coin[@]}"; do
    printf "%s\t$((i + 1)) ${coin[i]}\n"
done

printf "\n"

while true; do
    printf "\t"
    read -r coinNumber
    printf "\n"

    if [ "$coinNumber" -gt 0 ] && [ "$coinNumber" -lt 6 ]; then
        printf "%sAi ales ${coin[coinNumber - 1]}!\n"
        break
    fi

    printf "Numar invalid!\n"
done

printf "%s\nBalanta dumneavoastra este de: $balance ${coin[coinNumber - 1]}\n"

printf "\nAlegeti miza intre 5 si 50!"

while true; do
    printf "\t"
    read -r stake
    printf "\n"

    if [ "$stake" -gt 4 ] && [ "$coinNumber" -lt 51 ]; then
        printf "%sAi ales miza de $stake"
        break
    fi

    printf "Numar invalid!\n"
done

while true; do
    if [ "$balance" -lt 0 ] || [ "$balance" == 0 ]; then
        printf "\n\nDuteacas!"
        break
    fi

    printf "\n\n\nJoci(da/nu)?\n"

    printf "\t"
    read -r status
    printf "\n"

    if [ "$status" = "nu" ]; then
        break
    fi

    printf "\tAi dat cu zarul ... "

    user1=$RANDOM
    user2=$RANDOM
    ((user1 = user1 % 6 + 1))
    ((user2 = user2 % 6 + 1))

    sleep 1

    printf "%s$user1 cu $user2\n\n"

    printf "\tOponentul tau a dat ... "

    oponent1=$RANDOM
    oponent2=$RANDOM
    ((oponent1 = oponent1 % 6 + 1))
    ((oponent2 = oponent2 % 6 + 1))

    sleep 1
    printf "%s$oponent1 cu $oponent2\n\n"
    printf "\n"

    ((sumuser = user1 + user2))
    ((sumoponent = oponent1 + oponent2))

    if [ "$sumoponent" -lt "$sumuser" ]; then
        printf "%s\t\tAi castigat $stake ${coin[coinNumber - 1]}!"
        ((balance = balance + "$stake"))
    elif [ "$sumoponent" -gt "$sumuser" ]; then
        printf "%s\t\tAi pierdut $stake ${coin[coinNumber - 1]}!"
        ((balance = balance - "$stake"))
    else
        printf "\t\tRemiza!"
    fi

    printf "\n\n\t\t%sBalanta: $balance"

done

printf "%s\n\nBalantul final:$balance\n\nLa revedere!\n"
