# Copy this file to /etc/bash_completion.d/nofetch

_nofetch_completions() {
    local cur prev words cword options colors
    _init_completion -s || return

    options="--regular --lttstore --flex --help"
    colors="red green blue yellow magenta cyan"

    local color_selected=false
    local option_selected=false

    for word in "${COMP_WORDS[@]:1}"; do
        if [[ " $options " == *" $word "* ]]; then
            option_selected=true
        elif [[ " $colors " == *" $word "* ]]; then
            color_selected=true
        fi
    done

    if [[ "$color_selected" == true && "$option_selected" == true ]]; then
        return 0
    fi

    if [[ ${#COMP_WORDS[@]} -ge 3 ]]; then
       return 0
    fi

    if [[ "$cur" == --* ]]; then
        if [[ "$option_selected" == false ]]; then
            COMPREPLY=( $(compgen -W "$options" -- "$cur") )
        fi
    else
        COMPREPLY=()
        if [[ "$color_selected" == false ]]; then
            COMPREPLY+=( $(compgen -W "$colors" -- "$cur") )
        fi
        if [[ "$option_selected" == false && "$cur" != "" ]]; then
            COMPREPLY+=( $(compgen -W "$options" -- "$cur") )
        fi
    fi

    return 0
}

complete -F _nofetch_completions nofetch
