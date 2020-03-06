# Fetch

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)

Fetch libraries and interface for ReasonML/OCaml.

Fetch aims to provide a common interface over different HTTP and Promise-implementations in the ReasonML/OCaml ecosystem.

> A note is that Fetch is still in a phase where we're figuring out the API. In other words, the API
> may change and input is welcome!

## [Fetch Core](./src/fetch-core)

Provides a functor for creating and providing your own Fetch-implementation. The goal is to be pluggable with any HTTP or Promise-implementation provided it conforms to the common interface.

## [Fetch Native Lwt](./src/fetch-native-lwt)

![Windows](https://github.com/lessp/fetch/workflows/Windows/badge.svg)
![macOS](https://github.com/lessp/fetch/workflows/macOS/badge.svg)
![Ubuntu](https://github.com/lessp/fetch/workflows/Ubuntu/badge.svg)

A consumable fetch-library for ReasonML/OCaml native. Uses `Lwt` for its `Promise`-implementation.

## Contributing

Feel free to open an issue and/or grabbing one of the [open issues](https://github.com/lessp/reason-fetch/issues).

## Contributors

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://lessp.dev/"><img src="https://avatars3.githubusercontent.com/u/17602389?v=4" width="100px;" alt="Tom Ekander"/><br /><sub><b>Tom Ekander</b></sub></a><br /><a href="https://github.com/lessp/reason-fetch/commits?author=lessp" title="Code">💻</a> <a href="#ideas-lessp" title="Ideas, Planning, & Feedback">🤔</a> <a href="https://github.com/lessp/reason-fetch/commits?author=lessp" title="Documentation">📖</a></td>
    <td align="center"><a href="https://github.com/Et7f3"><img src="https://avatars2.githubusercontent.com/u/29592775?v=4" width="100px;" alt="Et7f3"/><br /><sub><b>Et7f3</b></sub></a><br /><a href="https://github.com/lessp/reason-fetch/commits?author=Et7f3" title="Code">💻</a> <a href="#ideas-Et7f3" title="Ideas, Planning, & Feedback">🤔</a> <a href="#review-Et7f3" title="Reviewed Pull Requests">👀</a></td>
    <td align="center"><a href="https://github.com/ulrikstrid"><img src="https://avatars3.githubusercontent.com/u/1607770?v=4" width="100px;" alt="Ulrik Strid"/><br /><sub><b>Ulrik Strid</b></sub></a><br /><a href="https://github.com/lessp/reason-fetch/commits?author=ulrikstrid" title="Code">💻</a> <a href="#ideas-ulrikstrid" title="Ideas, Planning, & Feedback">🤔</a> <a href="#review-ulrikstrid" title="Reviewed Pull Requests">👀</a></td>
    <td align="center"><a href="https://ostera.io"><img src="https://avatars0.githubusercontent.com/u/854222?v=4" width="100px;" alt="Leandro Ostera"/><br /><sub><b>Leandro Ostera</b></sub></a><br /><a href="#ideas-ostera" title="Ideas, Planning, & Feedback">🤔</a></td>
  </tr>
</table>

<!-- markdownlint-enable -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/kentcdodds/all-contributors) specification. Contributions of any kind welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details
