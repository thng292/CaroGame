#let template(doc) = [

    #set text(
    font: "Time News Roman",
    size: 14pt,
    lang: "vi",
    )

    #set page(
    paper: "a4",
    numbering: "1",
    margin: (top: 3cm, bottom: 2.5cm, left: 3cm, right: 2cm)
    )

    #set par(
        linebreaks: "optimized",
        justify: true,
        leading: 1em,
    )
    #show par: set block(spacing: 1.6em)

    #set outline(
        title: none,
        indent: true,
    )

    #set heading(
        numbering: "1.1."
    )

    #show heading.where(level: 1, numbering: "1.1."): it => [
        #pagebreak()
        #pad(
            top: 1.5em,
            bottom: 1.5em,
        )[
            #text(size: 20pt)[
                Chương #counter(heading).display() 
            ]
            #pad(top: 2pt)[
                #text(size: 24pt)[
                    #it.body
                ]
            ]
        ]
    ]

    #set figure(
        numbering: "1.1",
    )

    #show figure: block.with(
        breakable: false,
        width: 100%,
    )

    #show grid: block.with(
        breakable: false,
        width: 100%,
    )

    #set list(
        indent: 16pt,
        tight: false
    )

    // #show "Interface" : it => [*#it*]
    // #show "Usage" : it => [*#it*]
    // #show "Parameters" : it => [*#it*]
    // #show "Return" : it => [*#it*]
    #set raw(
        lang: "cpp"
    )

    #show raw : it => [
        #par(leading: 0.65em, justify: false, linebreaks: "simple")[
            #text(style: "normal", weight: "medium", font: ("Cascadia Code", "Consolas"), it)
        ]
    ]

    #show raw.where(block: true): block.with(
        width: 100%,
        fill: luma(240),
        inset: 4pt,
        outset: (y: 3pt),
        radius: 2pt,
        breakable: false,
    )

    #show raw.where(block: false): box.with(
        fill: luma(240),
        inset: (x: 3pt, y: 0pt),
        outset: (y: 3pt),
        radius: 2pt,
    )

    #set ref(
        supplement: it => {
            if it.func() == heading {
                if it.level == 1 {
                    return [Chương]
                } else {
                    return [Mục]
                }
            }
            if it.func() == figure {
                return [Hình]
            }
        },
    )

    #set table(
        align: left,
    )

    #show table : par.with(
        linebreaks: "simple",
        justify: false,
    )

    #show bibliography : it => par(justify: false, linebreaks: "simple")[
        #text(style: "normal", weight: "medium", it)
    ]

    #doc

]