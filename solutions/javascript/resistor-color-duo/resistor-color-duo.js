export const decodedValue = (colors) => {
    let values = {
        "black": "0",
        "brown": "1",
        "red": "2",
        "orange": "3",
        "yellow": "4",
        "green": "5",
        "blue": "6",
        "violet": "7",
        "grey": "8",
        "gray": "8",
        "white": "9"
    };

    return parseInt(values[colors[0]] + values[colors[1]]);
};
