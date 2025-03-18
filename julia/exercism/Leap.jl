"""
    is_leap_year(year)

Return `true` if `year` is a leap year in the gregorian calendar.

"""
function is_leap_year(year)
    x = false
    if year % 4 == 0
        if year % 100 == 0
            if year % 400 == 0
                x = true
            end
        else
            x = true
        end
    end
    return x
end

