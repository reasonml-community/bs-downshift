# `bs-downshift`

[BuckleScript](https://github.com/bucklescript/bucklescript) bindings for [Downshift](https://github.com/paypal/downshift) - **WIP**

## Demo

_Coming soon_

## Install and setup

#### yarn

```bash
$ yarn add bs-downshift
```

#### bsconfig

Add `bs-downshift` to your `bs-dependencies`: **bsconfig.json**

```json
"bs-dependencies": [
  "bs-downshift",
  "reason-react"
]
```

## Usage

```reason
type arrayOfItems = array(string);

module BasicAutocomplete = {
  let component = ReasonReact.statelessComponent("BasicAutocomplete");

  let make (~items: arrayOfItems, ~onChange, _children) => {
    ...component,
    render: _self =>
      <ReasonDownshift.Downshift
        onChange
        render=(
          renderFunc =>
            <div>
              (
                /*
                  NOTE: spreading props is discouraged in ReasonReact!
                  https://reasonml.github.io/reason-react/docs/en/props-spread.html
                  */
                ReasonReact.cloneElement(
                  <input />,
                  ~props=
                    ReasonDownshift.objToJsObj(
                      renderFunc##getInputProps(ReactDOMRe.props(~placeholder="Favorite color ?", ()))
                    ),
                  [||]
                )
              )
              {if (renderFunc##isOpen) {
                <div style=(ReactDOMRe.Style.make(~border="1px solid #ccc", ()))>
                  (
                    ReasonReact.arrayToElement(
                      items
                      |> Array.filter(
                          item => {
                            let inputValue = Js.Nullable.to_opt(renderFunc##inputValue);
                            switch inputValue {
                              | None => true
                              | Some(v) => Js.String.includes(
                                  String.lowercase(v),
                                  String.lowercase(item)
                                )
                            };
                          }
                        )
                      |> Array.mapi(
                        (index, item) => {
                          let backgroundColor = if (renderFunc##highlightedIndex === index) {
                            "gray"
                          } else {
                            "white"
                          };
                          let fontWeight = if (renderFunc##selectedItem === item) {
                            "bold"
                          } else {
                            "normal"
                          };
                          ReasonReact.cloneElement(
                            <div
                              key=item
                              style=(
                                ReactDOMRe.Style.make(
                                  ~backgroundColor=backgroundColor,
                                  ~fontWeight=fontWeight,
                                  ()
                                )
                              )
                            />,
                            ~props=(ReasonDownshift.objToJsObj(renderFunc##getItemProps({item}))),
                            [|item|]
                          )
                        }
                      )
                    )
                  )
                </div>;
              } else {
                ReasonReact.nullElement;
              }
            </div>
        )
      />
  };
};

module App = {
  let component = ReasonReact.statelessComponent("App");

  let make = (_children) => {
    ...component,
    render: _self =>
      <BasicAutocomplete
        items=([|'apple', 'orange', 'carrot'|])
        onChange=(selectedItem => Js.log(selectedItem))
      />
  };
};
```
