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
    #show figure: it => align(center)[
        #it.body
        Hình #counter(figure).display(it.numbering): #it.caption
    ]

    #set raw(
        lang: "cpp"
    )

    #set list(
        indent: 16pt,
        tight: false
    )

    // #show "Interface" : it => [*#it*]
    // #show "Usage" : it => [*#it*]
    // #show "Parameters" : it => [*#it*]
    // #show "Return" : it => [*#it*]

    #show raw : it => [
        #par(leading: 0.65em, justify: false)[
            #text(style: "normal", weight: "medium", it)
        ]
    ]

    #show raw.where(block: true): block.with(
        width: 100%,
        fill: luma(240),
        inset: 2pt,
        outset: (y: 3pt),
        radius: 2pt,
        breakable: false
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

    #doc

]

#let figureOutline() = locate(loc => {
        let figures = query(figure, loc)
        let res = ()
        for index, fig in figures [
            #grid(
                columns: (auto, auto, 1fr, auto, auto),
                rows: (auto),
                link(fig.location(), [Hình #(index+1). ] + fig.caption),
                h(4pt),
                repeat[.],
                h(4pt), 
                link(fig.location(), [#fig.location().page()])
            )
        ]
    })